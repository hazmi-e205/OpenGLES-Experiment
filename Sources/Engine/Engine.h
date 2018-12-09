//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_ENGINE_H
#define OGLES_ENGINE_H

#include "PlatformDefine.h"

#if defined(AndroidStudio)
#include "Engine/Platform/Android/PlatformAndroid.h"
#elif defined(VisualStudio)
#include "Engine/Platform/Win32/PlatformWin32.h"
#endif

#define MyEngine Engine::Get()

class Engine {
private:
    static Engine *myEngine;

public:
    static void Create();
    static bool isValid();
    static Engine *Get();
    Platform *GetPlatform();

    Engine();
    ~Engine();
};


#endif //OGLES_ENGINE_H
