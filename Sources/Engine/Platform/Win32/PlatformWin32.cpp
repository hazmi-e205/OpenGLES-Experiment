//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include <Engine/Utils/Speak.h>
#include "PlatformAndroid.h"

Platform *Platform::MyPlatform;

PlatformAndroid::PlatformAndroid() {
    Problem("PlatformAndroid");
}

PlatformAndroid::~PlatformAndroid() {
}

Platform *Platform::Get() {
    if (!MyPlatform)
        MyPlatform = new PlatformAndroid();

    return MyPlatform;
}
