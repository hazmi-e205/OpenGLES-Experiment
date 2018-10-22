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
  
  virtual void draw();
  virtual void scale(float scale_);
  virtual void rotationX(float rotate);
  virtual void rotationY(float rotate);
  virtual void rotationZ(float rotate);
  virtual void translation(Vector3 &transL);
};


#endif //OGLES_MODEL_H
