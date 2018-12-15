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

FileSystem *Engine::GetFS()
{
  return FileSystem::Get();
}

Engine::Engine() {
    if (GetPlatform() == nullptr)
        Problem("Platform not yet initialized");

}

Engine::~Engine() {
}

void Engine::Create() {
    if (!isValid())
        myEngine = new Engine();
}

void Engine::Shutdown()
{
  Platform::Destroy();
  FileSystem::Destroy();
  delete myEngine;
}
