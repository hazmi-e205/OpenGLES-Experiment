//
// Created by hazmi.arifin on 5/14/2018.
//

#ifndef OGLES_MODEL_H
#define OGLES_MODEL_H

#include "Vertex.h"
#include "OGLShader.h"

class Model {
public:
	Model();
	~Model();

private:
    const char* model_vs = ""
            "attribute vec3 a_posL;\n"
            "attribute vec2 a_uv;\n"
            "varying vec2 v_uv;\n"
            "attribute vec4 a_color;\n"
            "varying vec4 v_color;\n"
            "uniform mat4 u_mvp;\n"
            "void main()\n"
            "{\n"
            "v_color = a_color;\n"
            "v_uv = a_uv;\n"
            "vec4 posL = vec4(a_posL, 1.0);\n"
            "posL = u_mvp*posL;\n"
            "gl_Position = posL;\n"
            "}";

    const char* model_fs = ""
            "precision mediump float;\n"
            "varying vec4 v_color;\n"
            "uniform sampler2D u_texture;\n"
            "varying vec2 v_uv;\n"
            "void main()\n"
            "{\n"
            "gl_FragColor=texture2D(u_texture,v_uv);\n"
            "}";

    Matrix modelScale, modelRotationX, modelRotationY, modelRotationZ, modelTranslation, model_mvp;
    GLuint m_hVertexBuffer, m_hIndexBuffer, textureID;
    unsigned int m_noIndices, m_noVertices;
    Vertex *vertices_of_model;
    GLuint *indexData;
    OGLShader *ShaderObj;

public:
	void InitModel(const char * file_nfg, const char * file_tga);
    void drawModel();
    void scale(float scale_);
    void rotationX(float rotate);
    void rotationY(float rotate);
    void rotationZ(float rotate);
    void translation(Vector3 &transL);

    GLuint getVertexBufferID() { return m_hVertexBuffer; };
    GLuint getIndexBufferID() { return m_hIndexBuffer; };
    unsigned int getVertexNumber() { return m_noVertices; };
    unsigned int getIndexNumber() { return m_noIndices; };
};


#endif //OGLES_MODEL_H
