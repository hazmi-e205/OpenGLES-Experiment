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
    auto m_engine = MyEngine;
    auto m_platform = MyEngine->GetPlatform();
    auto m_fs = MyEngine->GetPlatform()->GetFS();

    MyEngine->GetPlatform()->GetFS()->setAssetManager(assetPtr);
}
