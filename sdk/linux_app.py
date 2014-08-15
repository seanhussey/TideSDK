
# 
# Copyright (c) 2012 - 2014 TideSDK contributors 
# http://www.tidesdk.org
# Includes modified sources under the Apache 2 License
# Copyright (c) 2008 - 2012 Appcelerator Inc
# Refer to LICENSE for details of distribution and use.
# 

import effess
import os
import os.path as p
from app import App

class LinuxApp(App):
    def stage(self, stage_dir, bundle, no_install, js_obfuscate, ignore_patterns):
        App.stage(self, stage_dir, bundle=bundle, no_install=no_install, js_obfuscate=js_obfuscate, ignore_patterns=ignore_patterns)

        contents = self.get_contents_dir()
        self.env.log(u'Copying tiboot to %s' % contents)
        self.executable_path = p.join(self.contents, self.name)
        effess.copy(p.join(self.sdk_dir, 'tiboot'), self.executable_path)

    def package(self, package_dir, bundle=False):
        longname = self.name + "-" + self.version
        def tar_callback(f, tar_file):
            print f
            # tar paths in <= 2.5 must be non unicode
            f = f.encode('ascii', 'ignore')
            tarname = longname + "/" + f.replace(self.stage_dir + os.sep, "")
            tarname = tarname.encode('ascii', 'ignore')
            tar_file.add(f, tarname)

        f = p.join(package_dir, longname + ".tgz")
        cmd = "cd \"" + self.stage_dir + "\" ;tar cvzf \"" + f + "\" \"./\""
        print cmd
        os.system(cmd)
