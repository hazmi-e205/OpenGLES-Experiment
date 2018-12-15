//
// Created by hazmi.arifin on 5/2/2018.
//

#include "Engine/Platform/Android/Implement.h"

void setDataDir (const char* datadir)
{
    MyEngine->GetFS()->SetAppDirectory(datadir);
}

void setAssetMgr (AAssetManager* assetPtr)
{
    MyEngine->GetFS()->setAssetManager(assetPtr);
}
