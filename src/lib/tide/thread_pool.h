/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <ctime>

#include <list>
#include <queue>

#include <Poco/SharedPtr.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/Mutex.h>
#include <Poco/Event.h>

#include "tide.h"

namespace tide
{
    typedef Poco::SharedPtr<Poco::Runnable> SharedRunnable;
    typedef std::queue<SharedRunnable> PoolJobQueue;

    class PooledThread;
    typedef std::list<PooledThread*> PooledThreadList;

    class TIDE_API ThreadPool
    {
        friend class PooledThread;

    public:
        ThreadPool(
            int minCapacity = 2,
            int maxCapacity = 10,
            int idleSeconds = 60,
            int queueMax = -1
        );
        virtual ~ThreadPool();

        bool start(SharedRunnable target, bool queue = true);
        void pauseAll();

        int availableThreads();
        int totalThreads();
        void collect();

    protected:
        virtual bool canSpawnThread();

        int minCapacity, maxCapacity;
        int idleSeconds;
        int queueMax;

    private:
        PooledThread* getIdleThread();

        SharedRunnable getJob();
        void addJob(SharedRunnable job);

        PooledThreadList threads;
        Poco::Mutex threadsMutex;

        PoolJobQueue pendingJobs;
        Poco::Mutex jobsMutex;
    };

    class TIDE_API PooledThread : public Poco::Thread, public Poco::Runnable
    {
    public:
        PooledThread(ThreadPool* pool);
        virtual ~PooledThread();

        enum State {
            IDLE,
            PAUSING,
            RESERVED,
            WORKING,
            POWERDOWN,
            DEAD
        };

        void start();
        void shutdown();
        void assignJob(SharedRunnable job);
        void resume();
        void pause(bool wait=false);
        void reserve();

        bool idle() { return state() == IDLE; }
        bool working() { return state() == WORKING; }
        bool alive() { return state() != DEAD; }

        int idleTime();

        void run();

    private:
        State state();
        void setState(State state);
        void work();

        State _state;
        Poco::Mutex stateMutex;
        Poco::Event wakeup, sleeping;
        SharedRunnable job;
        ThreadPool* pool;
        time_t idleStartTime;
    };
}

#endif
