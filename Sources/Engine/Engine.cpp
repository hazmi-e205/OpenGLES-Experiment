//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include "Engine.h"

#if defined(AndroidStudio)
#include "Engine/Platform/Android/PlatformAndroid.h"
#elif defined(VisualStudio)
#include "Engine/Platform/Win32/PlatformWin32.h"
#endif

bool Engine::isValid() {
    if (myEngine != nullptr)
        return true;

    return false;
}

Engine *Engine::Get() {
    if (!isValid())
        myEngine = new Engine();

    return myEngine;
}

Platform *Engine::GetPlatform() {
    if (myPlatform == nullptr)
    {
#if defined(AndroidStudio)
        myPlatform = new PlatformAndroid();
#elif defined(VisualStudio)
        myPlatform = new PlatformWin32();
#endif
    }
    return myPlatform;
}
