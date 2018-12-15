//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_PLATFORM_H
#define OGLES_PLATFORM_H

#include "PlatformDefine.h"

#if defined(AndroidStudio)
#include <Engine/Platform/Android/FileSystem.h>
#elif defined(VisualStudio)
#include <Engine/Platform/Win32/FileSystem.h>
#endif

class Platform {
protected:
    static Platform *MyPlatform;

public:
    static Platform *Get();
    static void Shutdown();
};


#endif //OGLES_PLATFORM_H
