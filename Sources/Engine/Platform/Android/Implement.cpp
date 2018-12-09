//
// Created by hazmi.arifin on 5/2/2018.
//

#include "Engine/Platform/Android/Implement.h"

void setDataDir (const char* datadir)
{
    MyEngine->GetPlatform()->GetFS()->SetAppDirectory(datadir);
}

void setAssetMgr (AAssetManager* assetPtr)
{
    MyEngine->GetPlatform()->GetFS()->setAssetManager(assetPtr);
}
