#ifndef OGLADAPTER_H
#define OGLADAPTER_H

#include <QOpenGLWidget>
#include <QOpenGLBuffer>

void glGenBuffers(GLsizei n, GLuint *buffers);
void glBindBuffer (GLenum target, GLuint buffer);
void glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);

#endif // OGLADAPTER_H
