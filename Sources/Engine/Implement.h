//
// Created by hazmi.arifin on 5/2/2018.
//

#ifndef OGLES_IMPLEMENT_H
#define OGLES_IMPLEMENT_H

#include "PlatformDefine.h"

#if defined (AndroidStudio)
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#endif

//On App
void native_init();

//OpenGLES2
void native_gl_init(int width, int height);
void native_gl_draw();
void getScreen(int &width, int &height);
float getAspectRatio();

//DataFiles Dir
void setDataDir (const char* datadir);
const char* getDataDir ();

#if defined (AndroidStudio)
void setAssetMgr (AAssetManager* assetPtr);
AAssetManager* getAssetMgr();
#endif

void readTestExternal();
void readTestInternal();

#endif //OGLES_IMPLEMENT_H
