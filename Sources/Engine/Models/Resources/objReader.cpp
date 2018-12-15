#include "objReader.h"
#include <string>
#include <string.h>
#include <Engine/Engine.h>
#include "Implement.h"
#include "Engine/Utils/Speak.h"
#include "PlatformDefine.h"

objReader::objReader(const char * file_obj)
{
  FILE* pFile = MyEngine->GetFS()->GetFile(file_obj, "r");
  if (pFile == NULL) {
    Problem("Load File: %s is not found", file_obj);
    return;
  }

  //Let's read till drop
  int vertex_num = 0;
  int uv_num = 0;
  int index_num = 0;
  int indexUV_num = 0;
  std::vector<Vector2> uvs_temp;
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
      Say("UV Indices: %d", indexUV_num);
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

      //uvs_temp.push_back(uv);
      uvs_of_model.push_back(uv);
      //uvs_of_model.push_back(Vector2(0.0f, 0.0f));
      uv_num++;
    }
    else if (strcmp(lineHeader, "f") == 0) 
    {
      unsigned int vertexIndex[3], uvIndex[3];
      int matches = fscanf(pFile, "%d/%d/%*d %d/%d/%*d %d/%d/%*d\n", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);
      if (matches != 6) {
        Problem("File can't be read by our simple parser : Try exporting with other options <indices>");
        return;
      }
      indices_of_model.push_back(vertexIndex[0] - 1);
      indices_of_model.push_back(vertexIndex[1] - 1);
      indices_of_model.push_back(vertexIndex[2] - 1);
      index_num += 3;

      uvs_indices.push_back(uvIndex[0] - 1);
      uvs_indices.push_back(uvIndex[1] - 1);
      uvs_indices.push_back(uvIndex[2] - 1);
      indexUV_num += 3;

      //uvs_of_model.push_back(Vector2(0.0f, 0.0f));
    }
  }
  //reaarange
  /*for (unsigned int idx = 0; idx < uvs_of_model.size(); idx++)
  {
    uvs_of_model.at(idx) = uvs_temp.at(uvs_indices.at(idx));
  }*/
}


objReader::~objReader()
{
}
