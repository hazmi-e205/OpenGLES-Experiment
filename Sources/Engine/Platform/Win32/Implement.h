//
// Created by hazmi.arifin on 5/2/2018.
//

#ifndef OGLES_IMPLEMENT_ANDROID_H
#define OGLES_IMPLEMENT_ANDROID_H

#include "Engine/Engine.h"
#include "Engine/Platform/Android/FileSystem.h"

//DataFiles Dir
void setDataDir (const char* datadir);
void setAssetMgr (AAssetManager* assetPtr);

#endif //OGLES_IMPLEMENT_ANDROID_H
