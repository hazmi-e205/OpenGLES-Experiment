#pragma once

#include <vector>
#include "Vertex.h"
#include "OGLAdapter.h"

class nfgReader
{
private:
  std::vector<Vertex> vertices_of_model;
  std::vector<GLuint> indices_of_model;
  unsigned int n_vertices, n_indices;

public:
  Vertex *getVertices() { return &vertices_of_model.front(); };
  GLuint *getIndices() { return &indices_of_model.front(); };
  unsigned int getLengthVetices() { return vertices_of_model.size(); };
  unsigned int getLengthIndices() { return indices_of_model.size(); };

  nfgReader(const char * file_nfg);
  ~nfgReader();
};

