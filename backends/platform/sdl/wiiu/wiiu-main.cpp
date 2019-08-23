/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include <wut.h>

#include "common/scummsys.h"
#include "backends/platform/sdl/wiiu/wiiu.h"
#include "backends/plugins/sdl/sdl-provider.h"
#include "base/main.h"
#include <whb/proc.h>


#ifdef __WIIU_DEBUG__
#include <whb/log_console.h>
#include <whb/log_cafe.h>
#include <whb/log.h>
#include <whb/crash.h>
#endif

int main(int argc, char *argv[]) {
    WHBProcInit();
    WHBInitCrashHandler();

#ifdef __WIIU_DEBUG__
    WHBLogConsoleInit();
    WHBLogCafeInit();
    WHBLogPrint("Logging initialized");
    WHBLogConsoleDraw();

#endif

	// Create our OSystem instance
    //g_system = new OSystem_Wiiu();
    //assert(g_system);

	// Pre initialize the backend
    //((OSystem_Wiiu *)g_system)->init();

#ifdef DYNAMIC_MODULES
	PluginManager::instance().addPluginProvider(new SDLPluginProvider());
#endif

	// Invoke the actual ScummVM main entry point:
    //int res = scummvm_main(argc, argv);

	// Free OSystem
    //g_system->destroy();

    while (WHBProcIsRunning()) {
        #ifdef __WIIU_DEBUG__
        WHBLogConsoleDraw();
        #endif
    }

#ifdef __WIIU_DEBUG__
    WHBLogCafeDeinit();
    WHBLogConsoleFree();
#endif
    WHBProcShutdown();
    return 1;
    //return res;
}
