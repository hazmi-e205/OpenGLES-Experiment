//
// Created by hazmi.arifin on 5/19/2018.
//

#ifndef OGLES_VERTEX_H
#define OGLES_VERTEX_H

#include <GLES2/gl2.h>
#include "Mystic.h"

struct Vertex
{
    Vector3 position;
    Vector2 uv;
    Vector4 color;
    Vector3 norm, binorm, tgt;
};

#endif //OGLES_VERTEX_H
