//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include <Engine/Utils/Speak.h>
#include "PlatformWin32.h"

Platform *Platform::MyPlatform;

PlatformWin32::PlatformWin32() {
    Problem("PlatformWin32");
}

PlatformWin32::~PlatformWin32() {
}

Platform *Platform::Get() {
    if (!MyPlatform)
        MyPlatform = new PlatformWin32();

    return MyPlatform;
}
