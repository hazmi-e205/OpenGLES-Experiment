//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include <Engine/Utils/Speak.h>
#include "PlatformAndroid.h"

Platform *Platform::MyPlatform;

Platform::Platform() {
    Speak("PlatformAndroid");
}

Platform::~Platform() {
}

Platform *Platform::Get() {
    if (!MyPlatform)
        MyPlatform = new Platform();

    return MyPlatform;
}

void Platform::Destroy()
{
  delete MyPlatform;
}
