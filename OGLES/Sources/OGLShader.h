//
// Created by hazmi.arifin on 6/2/2018.
//

#ifndef OGLES_OGLSHADER_H
#define OGLES_OGLSHADER_H

#include "PlatformDefine.h"

#if defined (AndroidStudio)
#include <GLES2/gl2.h>

#elif defined (QtProject)
#include "OGLAdapter.h"

#endif

class OGLShader {
public:
    struct Attributes
    {
        GLint position;
        GLint uv;
        GLint color;
    };

    struct Uniforms
    {
        GLint texture;
        GLint mvp;
    };

private:
    GLuint		m_program;

    Attributes	m_attributes;
    Uniforms	m_uniforms;

public:
    int			Init( const char * VertexShader, const char * FragmentShader );

    // Getters
    GLuint		GetProgram() const;
    Attributes	GetAttributes() const;
    Uniforms	GetUniforms() const;

    ~OGLShader();
};


#endif //OGLES_OGLSHADER_H
