//
// Created by hazmi.arifin on 5/2/2018.
//

#include <stdio.h>
#include "Implement.h"
#include "OGLRender.h"
#include "Speak.h"
#include "PlatformDefine.h"

#if defined (AndroidStudio)
AAssetManager* assetManagerPtr;
#endif

std::string dataDirApp;
int w_screen, h_screen;

void native_init()
{
    readTestExternal();
    readTestInternal();
}

void native_gl_init(int width, int height)
{
    w_screen = width;
    h_screen = height;
    setupGraphics(width,height);
}

void native_gl_draw()
{
    renderFrame();
}

void getScreen(int &width, int &height)
{
    width = w_screen;
    height = h_screen;
}

float getAspectRatio()
{
    return (float) w_screen / (float) h_screen;
}

void setDataDir (const char* datadir)
{
    dataDirApp = datadir;
}

std::string getDataDir()
{
    return dataDirApp;
}

#if defined (AndroidStudio)
void setAssetMgr (AAssetManager* assetPtr)
{
    assetManagerPtr = assetPtr;
}

AAssetManager* getAssetMgr()
{
    return assetManagerPtr;
}
#endif

void readTestExternal(){
    //std::string amo = "/storage/emulated/0/Android/data/id.hazmi.ogles/files/test.txt";
    std::string amo = getDataDir() + "/test.txt";
    Problem("External: %s", amo.c_str());
    FILE* pFile = fopen(amo.c_str(),"r");
    char dataread[100];
    unsigned n = 0;
    if (pFile != NULL) {
        while (fgets( dataread, 100, pFile ))
        {
            Say("%03u: %s", ++n, dataread);
        }
        fclose(pFile);
    } else {
        Problem("External Data Not Available");
    }
}
void readTestInternal(){
#if defined (AndroidStudio)
    AAsset* testAsset = AAssetManager_open(getAssetMgr(), "test.txt", AASSET_MODE_STREAMING);
    if (testAsset != NULL){
        char dataread[100];
        AAsset_read(testAsset, dataread, 100);
        Say("Internal: %s",dataread);
        AAsset_close(testAsset);
        //delete dataread;
    }
#endif
}
