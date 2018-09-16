//
// Created by hazmi.arifin on 5/12/2018.
//

#ifndef OGLES_OGLNATIVE_H
#define OGLES_OGLNATIVE_H

#include "PlatformDefine.h"

#if defined (AndroidStudio)
#include <GLES2/gl2.h>

#elif defined (QtProject)
#include "OGLAdapter.h"

#endif

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource);
GLuint loadShader(GLenum shaderType, const char* pSource);
char * LoadTGA( const char * szFileName, int * width, int * height, int * bpp );

void printGLString(const char *name, GLenum s);
void checkGlError(const char* op);
void printGLString(const char *name, GLenum s);

#endif //OGLES_OGLNATIVE_H
