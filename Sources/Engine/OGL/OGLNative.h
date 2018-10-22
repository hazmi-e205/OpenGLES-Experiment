//
// Created by hazmi.arifin on 5/12/2018.
//

#ifndef OGLES_OGLNATIVE_H
#define OGLES_OGLNATIVE_H

#include "OGLAdapter.h"

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource);
GLuint loadShader(GLenum shaderType, const char* pSource);

void printGLString(const char *name, GLenum s);
void checkGlError(const char* op);
void printGLString(const char *name, GLenum s);

#endif //OGLES_OGLNATIVE_H
