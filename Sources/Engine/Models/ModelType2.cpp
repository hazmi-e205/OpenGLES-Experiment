//
// Created by hazmi.arifin on 5/14/2018.
//

#include "ModelType2.h"
#include "Engine/OGL/OGLNative.h"
#include "Engine/Utils/Speak.h"
#include "Engine/Implement.h"
#include "Engine/Models/Resources/objReader.h"
#include "Engine/Models/Textures/TextureLoader.h"

ModelType2::ModelType2(const char * file_obj, const char * file_png)
{
  ShaderObj = new OGLShader();
  ShaderObj->Init(model_vs, model_fs);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  Say("OBJ: %s", file_obj);
  Speak("PNG: %s", file_png);
  objReader *myModel = new objReader(file_obj);

  glGenBuffers(1, &m_hVertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, m_hVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, myModel->getLengthVetices() * sizeof(Vector3), myModel->getVertices(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glGenBuffers(1, &m_hUVBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, m_hUVBuffer);
  glBufferData(GL_ARRAY_BUFFER, myModel->getLengthUV() * sizeof(Vector2), myModel->getUV(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glGenBuffers(1, &m_hIndexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_hIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, myModel->getLengthIndices() * sizeof(GLuint), myModel->getIndices(), GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  m_noIndices = myModel->getLengthIndices();

  //load texture
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
  TextureLoader *myTexture = new TextureLoader(file_png, TextureLoader::TextureMode::LOAD_RGB);
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


ModelType2::~ModelType2()
{
}

void ModelType2::draw() {
    glUseProgram(ShaderObj->GetProgram());
    glBindBuffer(GL_ARRAY_BUFFER, m_hVertexBuffer);
    if (ShaderObj->GetAttributes().position != -1)
    {
        glEnableVertexAttribArray(ShaderObj->GetAttributes().position);
        glVertexAttribPointer(ShaderObj->GetAttributes().position, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3), (char*)0);
    }

    if (ShaderObj->GetUniforms().mvp != -1)
    {
        //source: http://www.learnopengles.com/understanding-opengls-matrices/
        Matrix baru;
        baru.SetOrtho(-getAspectRatio(),getAspectRatio(),-1.f,1.f,-1.f,1.f);
        model_mvp = (modelScale * (modelRotationZ*modelRotationX*modelRotationY) * modelTranslation * baru);
        
        glUniformMatrix4fv(ShaderObj->GetUniforms().mvp, 1, GL_FALSE, *model_mvp.m);
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_hUVBuffer);
    if (ShaderObj->GetAttributes().uv != -1)
    {
        glEnableVertexAttribArray(ShaderObj->GetAttributes().uv);
        glVertexAttribPointer(ShaderObj->GetAttributes().uv, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), (char*)0);
    }

    glBindTexture(GL_TEXTURE_2D, textureID);
    if (ShaderObj->GetUniforms().texture != -1) {
        glUniform1i(ShaderObj->GetProgram(), ShaderObj->GetUniforms().texture);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_hIndexBuffer);
    glDrawElements(GL_TRIANGLES, m_noIndices, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ModelType2::scale(float scale_) {
    modelScale.SetScale(scale_);
}

void ModelType2::rotationX(float rotate) {
    modelRotationX.SetRotationX(rotate);
}

void ModelType2::rotationY(float rotate) {
    modelRotationY.SetRotationY(rotate);
}

void ModelType2::rotationZ(float rotate) {
    modelRotationZ.SetRotationZ(rotate);
}

void ModelType2::translation(Vector3 &transL) {
    modelTranslation.SetTranslation(transL);
}
