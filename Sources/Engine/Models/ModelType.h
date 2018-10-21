//
// Created by hazmi.arifin on 5/14/2018.
//

#ifndef OGLES_MODELTYPE_H
#define OGLES_MODELTYPE_H

#include "Engine/Utils/Mystic.h"

class ModelType {
public:
	//ModelType();
	//~ModelType();
  
  void draw();
  void scale(float scale_);
  void rotationX(float rotate);
  void rotationY(float rotate);
  void rotationZ(float rotate);
  void translation(Vector3 &transL);
};


#endif //OGLES_MODEL_H
