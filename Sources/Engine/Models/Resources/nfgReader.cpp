#include "nfgReader.h"
#include <string>
#include "Implement.h"
#include "Engine/Utils/Speak.h"
#include "PlatformDefine.h"
#if defined(AndroidStudio)
#include <AssetNative.h>
#endif

nfgReader::nfgReader(const char * file_nfg)
{
  FILE* pFile = NULL;
#if defined (AndroidStudio)
  pFile = asset_fopen(file_nfg, "r");
  if (pFile == NULL) {
    Problem("Load Internal: Model Vertices (.nfg) is not available on asset");
  }
#endif
  if (pFile == NULL) {
    std::string nfg_src = std::string(getDataDir()) + "/" + file_nfg;
    pFile = fopen(nfg_src.c_str(), "r");
    if (pFile == NULL) {
      Problem("Load External: %s", nfg_src.c_str());
      Problem("Load External: Model Vertices (.nfg) is not available files directory");
      return;
    }
  }

  //read Verices number
  fscanf(pFile, "NrVertices: %u", &n_vertices);

  //file to RAM
  unsigned int v_no = 0;
  for (unsigned int vertNo = 0; vertNo < n_vertices; vertNo++)
  {
    Vertex tempVertex;
    fscanf(pFile, "   %d. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%f, %f, %f]; tgt:[%f, %f, %f]; uv:[%f, %f];",
      &v_no,
      &tempVertex.position.x, &tempVertex.position.y, &tempVertex.position.z,
      &tempVertex.norm.x, &tempVertex.norm.y, &tempVertex.norm.z,
      &tempVertex.binorm.x, &tempVertex.binorm.y, &tempVertex.binorm.z,
      &tempVertex.tgt.x, &tempVertex.tgt.y, &tempVertex.tgt.z,
      &tempVertex.uv.x, &tempVertex.uv.y);
    vertices_of_model.push_back(tempVertex);
  }
  if (n_vertices == vertices_of_model.size())
    Say("Vertice OK!\nLast:%0.2f\n", vertices_of_model[n_vertices - 1].uv.y);
  else
    Problem("Vertice Corrupted! %u\n", v_no);

  //read indeces number
  fscanf(pFile, "\nNrIndices: %u\n", &n_indices);

  //file to RAM
  unsigned int i_no = 0;
  for (unsigned int i_No = 0; i_No < (n_indices / 3); i_No++) {
    GLuint tempIndex[3];
    fscanf(pFile, "%d.    %d,    %d,    %d\n",
      &i_no, &tempIndex[0], &tempIndex[1], &tempIndex[2]);
    
    indices_of_model.push_back(tempIndex[0]);
    indices_of_model.push_back(tempIndex[1]);
    indices_of_model.push_back(tempIndex[2]);
  }
  if (n_indices == indices_of_model.size())
    Say("Indeces OK!\nLast:%d\n", indices_of_model[n_indices - 1]);
  else
    Problem("Indeces Corrupted! %u\n", i_no);
}


nfgReader::~nfgReader()
{
}
