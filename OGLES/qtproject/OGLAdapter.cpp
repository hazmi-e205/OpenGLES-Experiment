#include "OGLAdapter.h"

QOpenGLBuffer m_arrayBuffer;
QOpenGLBuffer m_indexBuffer;

void glGenBuffers(GLsizei n, GLuint *buffers)
{
    buffers = m_arrayBuffer.create();
}

void glBindBuffer(GLenum target, GLuint buffer)
{
    m_arrayBuffer.bind();
}

void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
    m_arrayBuffer.allocate();
}
