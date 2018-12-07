//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include "Engine.h"

bool Engine::isValid() {
    if (myEngine != nullptr)
        return true;

    return false;
}

Engine *Engine::Get() {
    if (!isValid())
        Create();

    return myEngine;
}

void Engine::Create() {
    if (myEngine == nullptr)
        myEngine = new Engine();
}
