//
// Created by hazmi.arifin on 5/2/2018.
//

#include "Engine/Platform/Win32/ImplementWin32.h"

void setDataDir (const char* datadir)
{
    MyEngine->GetFS()->SetAppDirectory(datadir);
}