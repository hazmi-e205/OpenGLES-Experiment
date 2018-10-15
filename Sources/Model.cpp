//
// Created by hazmi.arifin on 5/14/2018.
//

#include "stdafx.h"
#include "Model.h"
#include <stdio.h>
#include "OGLNative.h"
#include "Speak.h"
#include "Implement.h"
#include <string>

#if defined (AndroidStudio)
#include "AssetNative.h"
#endif

Model::Model()
{
}


Model::~Model()
{
}

void Model::InitModel(const char * file_nfg, const char * file_tga)
{
    ShaderObj = new OGLShader();
    ShaderObj->Init(model_vs,model_fs);
    Say("NFG: %s", file_nfg);
    Speak("TGA: %s", file_tga);
    FILE* pFile = NULL;
#if defined (AndroidStudio)
    pFile = asset_fopen(file_nfg,"r");
    if (pFile == NULL) {
        Problem("Load Internal: Model Vertices (.nfg) is not available on asset");
    }
#endif
    if (pFile == NULL) {
        std::string nfg_src = std::string(getDataDir()) + "/" + file_nfg;
        pFile = fopen(nfg_src.c_str(), "r");
        if (pFile == NULL) {
            Problem("Load External: Model Vertices (.nfg) is not available files directory");
            return;
        }
    }

    //read Verices number
    fscanf(pFile,"NrVertices: %u", &m_noVertices);
    vertices_of_model = new Vertex[m_noVertices];

    //file to RAM
    unsigned int v_no = 0;
    for (unsigned int vertNo = 0; vertNo < m_noVertices; vertNo++) {
        fscanf(pFile, "   %d. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%f, %f, %f]; tgt:[%f, %f, %f]; uv:[%f, %f];",
               &v_no,
               &vertices_of_model[vertNo].position.x, &vertices_of_model[vertNo].position.y, &vertices_of_model[vertNo].position.z,
               &vertices_of_model[vertNo].norm.x, &vertices_of_model[vertNo].norm.y, &vertices_of_model[vertNo].norm.z,
               &vertices_of_model[vertNo].binorm.x, &vertices_of_model[vertNo].binorm.y, &vertices_of_model[vertNo].binorm.z,
               &vertices_of_model[vertNo].tgt.x, &vertices_of_model[vertNo].tgt.y, &vertices_of_model[vertNo].tgt.z,
               &vertices_of_model[vertNo].uv.x, &vertices_of_model[vertNo].uv.y);
    }
    if (v_no == m_noVertices - 1)
        Say("Vertice OK!\nLast:%0.2f\n", vertices_of_model[m_noVertices-1].uv.y);
    else
        Problem("Vertice Corrupted! %u\n", v_no);

    //read indeces number
    fscanf(pFile, "\nNrIndices: %u\n", &m_noIndices);
    indexData = new GLuint[m_noIndices];
    unsigned int i_no = 0, ind_no = -1;
    for (unsigned int i_No = 0; i_No < (m_noIndices/3); i_No++) {
        fscanf(pFile, "%d.    %d,    %d,    %d\n",
               &i_no, &indexData[ind_no+1], &indexData[ind_no + 2], &indexData[ind_no + 3]);
        ind_no += 3;
    }
    if (i_no == (m_noIndices/3) - 1)
        Say("Indeces OK!\nLast:%d\n", indexData[m_noIndices-1]);
    else
        Problem("Indeces Corrupted! %u\n", i_no);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glGenBuffers(1, &m_hVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_hVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_noVertices * sizeof(Vertex), vertices_of_model, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &m_hIndexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_hIndexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_noIndices * sizeof(GLuint), indexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //load texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    char *imageData = LoadTGA(file_tga, &width_texture, &height_texture, &bpp_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_texture, height_texture, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    delete[]vertices_of_model;
    delete[]indexData;
    delete imageData;

    modelScale.SetIdentity();
    modelRotationX.SetIdentity();
    modelRotationY.SetIdentity();
    modelRotationZ.SetIdentity();
    modelTranslation.SetIdentity();
    model_mvp.SetIdentity();
}

void Model::drawModel() {
    glUseProgram(ShaderObj->GetProgram());
    glBindBuffer(GL_ARRAY_BUFFER, m_hVertexBuffer);
    if (ShaderObj->GetAttributes().position != -1)
    {
        glEnableVertexAttribArray(ShaderObj->GetAttributes().position);
        glVertexAttribPointer(ShaderObj->GetAttributes().position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char*)0);
    }

    if (ShaderObj->GetUniforms().mvp != -1)
    {
        //source: http://www.learnopengles.com/understanding-opengls-matrices/
        Matrix baru;
        baru.SetOrtho(-getAspectRatio(),getAspectRatio(),-1.f,1.f,-1.f,1.f);
        model_mvp = (modelScale * (modelRotationZ*modelRotationX*modelRotationY) * modelTranslation * baru);


        glUniformMatrix4fv(ShaderObj->GetUniforms().mvp, 1, GL_FALSE, *model_mvp.m);
    }

    if (ShaderObj->GetAttributes().uv != -1)
    {
        glEnableVertexAttribArray(ShaderObj->GetAttributes().uv);
        glVertexAttribPointer(ShaderObj->GetAttributes().uv, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char*)0 + sizeof(Vertex::position));
    }

    glBindTexture(GL_TEXTURE_2D, textureID);
    if (ShaderObj->GetUniforms().texture != -1) {
        glUniform1i(ShaderObj->GetProgram(), ShaderObj->GetUniforms().texture);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_hIndexBuffer);
    glDrawElements(GL_TRIANGLES, m_noIndices, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Model::scale(float scale_) {
    modelScale.SetScale(scale_);
}

void Model::rotationX(float rotate) {
    modelRotationX.SetRotationX(rotate);
}

void Model::rotationY(float rotate) {
    modelRotationY.SetRotationY(rotate);
}

void Model::rotationZ(float rotate) {
    modelRotationZ.SetRotationZ(rotate);
}

void Model::translation(Vector3 &transL) {
    modelTranslation.SetTranslation(transL);
}
