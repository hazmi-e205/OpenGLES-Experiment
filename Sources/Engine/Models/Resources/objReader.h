#pragma once

#include <vector>
#include "Vertex.h"

class objReader
{
private:
  std::vector<Vector3> vertices_of_model;
  std::vector<GLuint> indices_of_model;
  std::vector<Vector2> uvs_of_model;
  unsigned int n_vertices, n_indices;

public:
  Vector3 *getVertices()  { return &vertices_of_model.front(); };
  GLuint  *getIndices()   { return &indices_of_model.front(); };
  Vector2 *getUV()        { return &uvs_of_model.front(); };
  unsigned int getLengthVetices() { return vertices_of_model.size(); };
  unsigned int getLengthIndices() { return indices_of_model.size(); };
  unsigned int getLengthUV()      { return uvs_of_model.size(); };

  objReader(const char * file_obj);
  ~objReader();
};

