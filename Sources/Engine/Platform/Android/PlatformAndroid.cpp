//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include "PlatformAndroid.h"
#include <android/log.h>
#include <Engine/Utils/Speak.h>

bool PlatformAndroid::isValid() {
    if (myPlatformAndroid != nullptr)
        return true;

    return false;
}

PlatformAndroid *PlatformAndroid::Get() {
    Speak("PlatformAndroid");

    if (!isValid())
        Create();

    return myPlatformAndroid;
}

void PlatformAndroid::Create() {
    if (myPlatformAndroid == nullptr)
        myPlatformAndroid = new PlatformAndroid();
}
