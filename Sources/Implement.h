//
// Created by hazmi.arifin on 5/2/2018.
//

#ifndef OGLES_IMPLEMENT_H
#define OGLES_IMPLEMENT_H

#include "PlatformDefine.h"

//On App
void native_init();

//OpenGLES2
void native_gl_init(int width, int height);
void native_gl_draw();
void native_cleanup();
void getScreen(int &width, int &height);
float getAspectRatio();

#endif //OGLES_IMPLEMENT_H
