/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "javascript_methods.h"
#include <Poco/Timer.h>

namespace tide
{
    // Common javascript functions that are re-implemented
    //  in the global scope so they are available without a window
    namespace JavaScriptMethods
    {
        void Bind(TiObjectRef global)
        {
            global->SetMethod("setTimeout", new FunctionPtrMethod(&SetTimeout));
            global->SetMethod("clearTimeout", new FunctionPtrMethod(&ClearTimeout));
            global->SetMethod("setInterval", new FunctionPtrMethod(&SetInterval));
            global->SetMethod("clearInterval", new FunctionPtrMethod(&ClearInterval));
        }
        
        class MainThreadCaller
        {
        public:
            TiMethodRef method;
            ValueList args;
            
            void OnTimer(Poco::Timer& timer)
            {
                Host::GetInstance()->RunOnMainThread(method, 0, args, true);
            }
        };
        
        static int currentTimerId = 0;
        static std::map<int, Poco::Timer*> timers;
        static std::map<int, MainThreadCaller*> callers;
        static Poco::Mutex timersMutex;
        
        static ValueRef CreateTimer(const ValueList& args, bool interval)
        {
            TiMethodRef method = 0;
            if (args.at(0)->IsMethod())
            {
                method = args.GetMethod(0);
            }
            else if (args.at(0)->IsString())
            {
                // TODO -- create a function from evaluatable code
            }
            
            long duration = (long)args.at(1)->ToDouble();
            ValueList methodArgs;
            for (size_t i = 2; i < args.size(); i++)
            {
                methodArgs.push_back(args.at(i));
            }
            
            if (!method.isNull())
            {
                Poco::ScopedLock<Poco::Mutex> l(timersMutex);
                int id = currentTimerId;
                timers[id] = new Poco::Timer(duration, interval ? duration : 0);
                callers[id] = new MainThreadCaller();
                callers[id]->method = method;
                callers[id]->args = methodArgs;
                
                Poco::TimerCallback<MainThreadCaller> callback(*callers[id], &MainThreadCaller::OnTimer);
                timers[id]->start(callback);
                
                currentTimerId++;
                return Value::NewInt(id);
            }
            else
            {
                throw ValueException::FromString("Unable to get method for executing on timeout");
            }
        }
        
        // this gets called on the main thread to avoid deadlock during the thread callback
        static ValueRef StopTimer(const ValueList& args)
        {
            int id = args.GetInt(0);
            Poco::ScopedLock<Poco::Mutex> l(timersMutex);
            
            std::map<int, Poco::Timer*>::iterator timerIter = timers.find(id);
            std::map<int, MainThreadCaller*>::iterator callerIter = callers.find(id);
            if (timerIter != timers.end() && callerIter != callers.end())
            {
                MainThreadCaller* caller = callerIter->second;
                Poco::Timer* timer = timerIter->second;
                
                // same as stop() but safe to be called from within the Timer callback
                timer->restart(0);
                callers.erase(callerIter);
                timers.erase(timerIter);
                delete caller;
                delete timer;
                
                return Value::NewBool(true);
            }
            return Value::NewBool(false);
        }
        
        ValueRef SetTimeout(const ValueList& args)
        {
            args.VerifyException("setTimeout", "m|s i");
            return CreateTimer(args, false);
        }
        
        ValueRef SetInterval(const ValueList& args)
        {
            args.VerifyException("setInterval", "m|s i");
            return CreateTimer(args, true);
        }
        
        ValueRef ClearTimeout(const ValueList& args)
        {
            args.VerifyException("clearTimeout", "i");
            return Host::GetInstance()->RunOnMainThread(new FunctionPtrMethod(&StopTimer), 0, args, false);
        }
        
        ValueRef ClearInterval(const ValueList& args)
        {
            args.VerifyException("clearInterval", "i");
            return Host::GetInstance()->RunOnMainThread(new FunctionPtrMethod(&StopTimer), 0, args, false);
        }
    }
}
