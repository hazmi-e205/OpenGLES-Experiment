//
// Created by hazmi.arifin on 5/26/2018.
//

#ifndef OGLES_MYSTIC_H
#define OGLES_MYSTIC_H

#include "Engine/OGL/OGLAdapter.h"

//Vector2

class Vector2
{
public:
    //Constructors
    Vector2() : x(0.0f), y(0.0f){}
    Vector2(GLfloat _x, GLfloat _y) : x(_x), y(_y) {}
    Vector2(GLfloat * pArg) : x(pArg[0]), y(pArg[1]) {}
    Vector2(const Vector2 & vector) : x(vector.x), y(vector.y) {}

    //Vector's operations
    GLfloat Length();
    Vector2 & Normalize();
    Vector2 operator + (const Vector2 & vector);
    Vector2 & operator += (const Vector2 & vector);
    Vector2 operator - ();
    Vector2 operator - (const Vector2 & vector);
    Vector2 & operator -= (const Vector2 & vector);
    Vector2 operator * (GLfloat k);
    Vector2 & operator *= (GLfloat k);
    Vector2 operator / (GLfloat k);
    Vector2 & operator /= (GLfloat k);
    Vector2 & operator = (const Vector2 & vector);
    Vector2 Modulate(const Vector2 & vector);
    GLfloat Dot(const Vector2 & vector);

    //access to elements
    GLfloat operator [] (unsigned int idx);

    //data members
    GLfloat x;
    GLfloat y;
};

//Vector3

class Vector3
{
public:
    //Constructors
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z) {}
    Vector3(GLfloat * pArg) : x(pArg[0]), y(pArg[1]), z(pArg[2]) {}
    Vector3(const Vector3 & vector) : x(vector.x), y(vector.y), z(vector.z) {}

    //Vector's operations
    GLfloat Length();
    Vector3 & Normalize();
    Vector3 operator + (const Vector3 & vector);
    Vector3 & operator += (const Vector3 & vector);
    Vector3 operator - ();
    Vector3 operator - (const Vector3 & vector);
    Vector3 & operator -= (const Vector3 & vector);
    Vector3 operator * (GLfloat k);
    Vector3 & operator *= (GLfloat k);
    Vector3 operator / (GLfloat k);
    Vector3 & operator /= (GLfloat k);
    Vector3 & operator = (const Vector3 & vector);
    Vector3 Modulate(const Vector3 & vector);
    GLfloat Dot(const Vector3 & vector);
    Vector3 Cross(const Vector3 & vector);

    //access to elements
    GLfloat operator [] (unsigned int idx);

    // data members
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

//Vector4

class Matrix;

class Vector4
{
public:
    //Constructors
    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vector4(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z), w(1.0f) {}
    Vector4(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w) : x(_x), y(_y), z(_z), w(_w) {}
    Vector4(GLfloat * pArg) : x(pArg[0]), y(pArg[1]), z(pArg[2]), w(pArg[3]) {}
    Vector4(const Vector3 & vector) : x(vector.x), y(vector.y), z(vector.z), w(1.0f){}
    Vector4(const Vector3 & vector, GLfloat _w) : x(vector.x), y(vector.y), z(vector.z), w(_w) {}
    Vector4(const Vector4 & vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}

    //Vector's operations
    GLfloat Length();
    Vector4 & Normalize();
    Vector4 operator + (const Vector4 & vector);
    Vector4 & operator += (const Vector4 & vector);
    Vector4 operator - ();
    Vector4 operator - (const Vector4 & vector);
    Vector4 & operator -= (const Vector4 & vector);
    Vector4 operator * (GLfloat k);
    Vector4 & operator *= (GLfloat k);
    Vector4 operator / (GLfloat k);
    Vector4 & operator /= (GLfloat k);
    Vector4 & operator = (const Vector4 & vector);
    Vector4 Modulate(const Vector4 & vector);
    GLfloat Dot(const Vector4 & vector);

    //matrix multiplication
    Vector4 operator * (const Matrix & m );

    //access to elements
    GLfloat operator [] (unsigned int idx);

    //data members
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
};

//Matrix 4 X 4


class Matrix
{
public:
    //constructors
    Matrix() {}
    Matrix(GLfloat val);
    Matrix(const Matrix & mat);

    // Matrix operations
    Matrix & SetZero();
    Matrix & SetIdentity();

    Matrix & SetRotationX(GLfloat angle);
    Matrix & SetRotationY(GLfloat angle);
    Matrix & SetRotationZ(GLfloat angle);
    Matrix & SetRotationAngleAxis( float angle, float x, float y, float z );

    Matrix & SetScale(GLfloat scale);
    Matrix & SetScale(GLfloat scaleX, GLfloat scaleY, GLfloat scaleZ);
    Matrix & SetScale(GLfloat * pScale);
    Matrix & SetScale(const Vector3 &scaleVec);

    Matrix & SetTranslation(GLfloat x, GLfloat y, GLfloat z);
    Matrix & SetTranslation(GLfloat *pTrans);
    Matrix & SetTranslation(const Vector3 &vec);

    Matrix & SetPerspective(GLfloat fovY, GLfloat aspect, GLfloat nearPlane, GLfloat farPlane);
    Matrix & SetFrustum(float l, float r, float b, float t, float n, float f);
    Matrix & SetOrtho(float l, float r, float b, float t, float n, float f);
    Matrix Transpose();
    Matrix Inverse();

    Matrix operator + (const Matrix & mat);
    Matrix & operator += (const Matrix & mat);
    Matrix operator - (const Matrix & mat);
    Matrix &operator -= (const Matrix & mat);

    Matrix operator * (const Matrix & mat);
    Matrix operator * (const GLfloat k);
    Matrix & operator *= (GLfloat k);

    Vector4 operator * (const Vector4 & vec);

    Matrix & operator = (const Matrix & mat);

    //data members
    GLfloat m[4][4];
};

#endif //OGLES_MYSTIC_H
