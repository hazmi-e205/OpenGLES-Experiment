//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_ENGINE_H
#define OGLES_ENGINE_H

#include "Engine/Platform/Platform.h"

#define MyEngine Engine::Get()

class Engine {
private:
    Engine *myEngine;
    Platform *myPlatform;

public:
    bool isValid();
    Engine *Get();
    Platform *GetPlatform();
};


#endif //OGLES_ENGINE_H
