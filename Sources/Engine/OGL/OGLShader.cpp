//
// Created by hazmi.arifin on 6/2/2018.
//

#include "OGLShader.h"
#include "OGLNative.h"

int OGLShader::Init( const char * VertexShader, const char * FragmentShader)
{
    m_program = createProgram( VertexShader, FragmentShader );

    //finding location of attributes
    m_attributes.position = glGetAttribLocation( m_program, "a_posL" );
    m_attributes.uv = glGetAttribLocation(m_program, "a_uv");
    m_attributes.color = glGetAttribLocation(m_program, "a_color");

    //finding location of uniforms
    m_uniforms.mvp= glGetUniformLocation(m_program, "u_mvp");
    m_uniforms.texture = glGetUniformLocation(m_program, "u_texture");

    return 0;
}

GLuint OGLShader::GetProgram() const
{
    return m_program;
}

OGLShader::Attributes OGLShader::GetAttributes() const
{
    return m_attributes;
}

OGLShader::Uniforms OGLShader::GetUniforms() const
{
    return m_uniforms;
}

OGLShader::~OGLShader()
{
    glDeleteProgram( m_program );
}