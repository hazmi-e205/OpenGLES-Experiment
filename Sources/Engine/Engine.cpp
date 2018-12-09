//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include <Engine/Utils/Speak.h>
#include "Engine.h"

Engine *Engine::myEngine;

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
    return Platform::Get();
}

Engine::Engine() {
    if (GetPlatform() == nullptr)
        Problem("Platform not yet initialized");

}

Engine::~Engine() {
    delete myEngine;
}

void Engine::Create() {
    if (!isValid())
        myEngine = new Engine();
}
