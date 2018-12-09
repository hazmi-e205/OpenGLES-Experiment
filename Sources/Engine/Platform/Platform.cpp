//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include <Engine/Utils/Speak.h>
#include "Platform.h"

FileSystem *Platform::GetFS() {
    Problem("Platform::GetFS");
    return FileSystem::Get();;
}