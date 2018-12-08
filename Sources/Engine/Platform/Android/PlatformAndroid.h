//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_PLATFORM_ANDROID_H
#define OGLES_PLATFORM_ANDROID_H

#include "Engine/Platform/Platform.h"

class PlatformAndroid : public Platform{
private:
    PlatformAndroid *myPlatformAndroid;

public:
    void Create();
    bool isValid();
    PlatformAndroid *Get();

};


#endif //OGLES_PLATFORM_ANDROID_H
