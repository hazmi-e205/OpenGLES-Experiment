#include "stdafx.h"
#include "objReader.h"
#include <string>
#include <string.h>
#include "Engine/Implement.h"
#include "Engine/Utils/Speak.h"
#include "PlatformDefine.h"
#if defined(AndroidStudio)
#include <AssetNative.h>
#endif

objReader::objReader(const char * file_obj)
{
  FILE* pFile = NULL;
#if defined (AndroidStudio)
  pFile = asset_fopen(file_obj, "r");
  if (pFile == NULL) {
    Problem("Load Internal: Model Vertices (.obj) is not available on asset");
  }
#endif
  if (pFile == NULL) {
    std::string obj_src = std::string(getDataDir()) + "/" + file_obj;
    pFile = fopen(obj_src.c_str(), "r");
    if (pFile == NULL) {
      Problem("Load External: Model Vertices (.obj) is not available files directory");
      return;
    }
  }

  //Let's read till drop
  int vertex_num = 0;
  int uv_num = 0;
  int index_num = 0;
  while (1)
  {
    char lineHeader[128];
    // read the first word of the line
    int res = fscanf(pFile, "%s", lineHeader);
    if (res == EOF)
    {
      n_indices = index_num;
      Speak("Vertice: %d", vertex_num);
      Say("UV's: %d", uv_num);
      Speak("Indices: %d", index_num);
      break; // EOF = End Of File. Quit the loop.
    }

    if (strcmp(lineHeader, "v") == 0)
    {
      Vector3 vertex;
      int matches = fscanf(pFile, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
      if (matches != 3) {
        Problem("File can't be read by our simple parser : Try exporting with other options <vertice>");
        return;
      }

      vertices_of_model.push_back(vertex);
      vertex_num++;
    }
    else if (strcmp(lineHeader, "vt") == 0)
    {
      Vector2 uv;
      int matches = fscanf(pFile, "%f %f\n", &uv.x, &uv.y);
      if (matches != 2) {
        Problem("File can't be read by our simple parser : Try exporting with other options <uv's>");
        return;
      }

      uvs_of_model.push_back(uv);
      uv_num++;
    }
    else if (strcmp(lineHeader, "f") == 0) 
    {
      unsigned int vertexIndex[3];
      int matches = fscanf(pFile, "%d/%*d/%*d %d/%*d/%*d %d/%*d/%*d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
      if (matches != 3) {
        Problem("File can't be read by our simple parser : Try exporting with other options <indices>");
        return;
      }
      indices_of_model.push_back(vertexIndex[0] - 1);
      indices_of_model.push_back(vertexIndex[1] - 1);
      indices_of_model.push_back(vertexIndex[2] - 1);
      index_num += 3;
    }
  }
}


objReader::~objReader()
{
}
