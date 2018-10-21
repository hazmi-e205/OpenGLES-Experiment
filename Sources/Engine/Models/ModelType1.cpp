//
// Created by hazmi.arifin on 5/14/2018.
//

#include "stdafx.h"
#include "ModelType1.h"
#include "Engine/OGL/OGLNative.h"
#include "Engine/Utils/Speak.h"
#include "Engine/Implement.h"
#include "Engine/Models/Resources/tgaLoader.h"
#include "Engine/Models/Resources/nfgReader.h"

ModelType1::ModelType1(const char * file_nfg, const char * file_tga)
{
  ShaderObj = new OGLShader();
  ShaderObj->Init(model_vs, model_fs);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  Say("NFG: %s", file_nfg);
  Speak("TGA: %s", file_tga);
  nfgReader *myModel = new nfgReader(file_nfg);

  glGenBuffers(1, &m_hVertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, m_hVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, myModel->getLengthVetices() * sizeof(Vertex), myModel->getVertices(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glGenBuffers(1, &m_hIndexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_hIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, myModel->getLengthIndices() * sizeof(GLuint), myModel->getIndices(), GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  m_noIndices = myModel->getLengthIndices();

  //load texture
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
  tgaLoader *myTexture = new tgaLoader(file_tga);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, myTexture->getWidth(), myTexture->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, myTexture->getTexture());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  delete myTexture;
  delete myModel;

  modelScale.SetIdentity();
  modelRotationX.SetIdentity();
  modelRotationY.SetIdentity();
  modelRotationZ.SetIdentity();
  modelTranslation.SetIdentity();
  model_mvp.SetIdentity();
}

/*
ModelType::~ModelType()
{
}

ModelType::ModelType()
{
}
*/

ModelType1::~ModelType1()
{
}

void ModelType1::draw() {
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

void ModelType1::scale(float scale_) {
    modelScale.SetScale(scale_);
}

void ModelType1::rotationX(float rotate) {
    modelRotationX.SetRotationX(rotate);
}

void ModelType1::rotationY(float rotate) {
    modelRotationY.SetRotationY(rotate);
}

void ModelType1::rotationZ(float rotate) {
    modelRotationZ.SetRotationZ(rotate);
}

void ModelType1::translation(Vector3 &transL) {
    modelTranslation.SetTranslation(transL);
}
