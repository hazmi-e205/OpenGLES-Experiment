#include "stdafx.h"
#include "tgaLoader.h"
#include <string>
#include "PlatformDefine.h"
#include "Implement.h"
#include "Speak.h"

void tgaLoader::LoadCompressedImage(char * pDest, char * pSrc, TGA_HEADER * pHeader)
{
  int w = pHeader->width;
  int h = pHeader->height;
  int rowSize = w * pHeader->bits / 8;
  bool bInverted = ((pHeader->descriptor & (1 << 5)) != 0);
  char * pDestPtr = bInverted ? pDest + (h + 1) * rowSize : pDest;
  int countPixels = 0;
  int nPixels = w * h;

  while (nPixels > countPixels)
  {
    unsigned char chunk = *pSrc++;
    if (chunk < 128)
    {
      int chunkSize = chunk + 1;
      for (int i = 0; i < chunkSize; i++)
      {
        if (bInverted && (countPixels % w) == 0)
          pDestPtr -= 2 * rowSize;
        *pDestPtr++ = pSrc[2];
        *pDestPtr++ = pSrc[1];
        *pDestPtr++ = pSrc[0];
        pSrc += 3;
        if (pHeader->bits != 24)
          *pDestPtr++ = *pSrc++;
        countPixels++;
      }
    }
    else
    {
      int chunkSize = chunk - 127;
      for (int i = 0; i < chunkSize; i++)
      {
        if (bInverted && (countPixels % w) == 0)
          pDestPtr -= 2 * rowSize;
        *pDestPtr++ = pSrc[2];
        *pDestPtr++ = pSrc[1];
        *pDestPtr++ = pSrc[0];
        if (pHeader->bits != 24)
          *pDestPtr++ = pSrc[3];
        countPixels++;
      }
      pSrc += (pHeader->bits >> 3);
    }
  }
}

void tgaLoader::LoadUncompressedImage(char * pDest, char * pSrc, TGA_HEADER * pHeader)
{
  int w = pHeader->width;
  int h = pHeader->height;
  int rowSize = w * pHeader->bits / 8;
  bool bInverted = ((pHeader->descriptor & (1 << 5)) != 0);
  for (int i = 0; i < h; i++)
  {
    char * pSrcRow = pSrc +
      (bInverted ? (h - i - 1) * rowSize : i * rowSize);
    if (pHeader->bits == 24)
    {
      for (int j = 0; j < w; j++)
      {
        *pDest++ = pSrcRow[2];
        *pDest++ = pSrcRow[1];
        *pDest++ = pSrcRow[0];
        pSrcRow += 3;
      }
    }
    else
    {
      for (int j = 0; j < w; j++)
      {
        *pDest++ = pSrcRow[2];
        *pDest++ = pSrcRow[1];
        *pDest++ = pSrcRow[0];
        *pDest++ = pSrcRow[3];
        pSrcRow += 4;
      }
    }
  }
}

tgaLoader::tgaLoader(const char * file_tga)
{
  FILE* f = NULL;
#if defined (AndroidStudio)
  f = asset_fopen(szFileName, "r");
  if (f == NULL) {
    Problem("Load Internal: Model Texture (.tga) is not available on asset");
  }
#endif
  if (f == NULL) {
    std::string tga_src = std::string(getDataDir()) + "/" + file_tga;
    f = fopen(tga_src.c_str(), "r");
    if (f == NULL) {
      Problem("Load External: Model Texture (.tga) is not available files directory");
      return;
    }
  }

  TGA_HEADER header;
  fread(&header, sizeof(header), 1, f);

  fseek(f, 0, SEEK_END);
  int fileLen = ftell(f);
  fseek(f, sizeof(header) + header.identsize, SEEK_SET);

  if (header.imagetype != IT_COMPRESSED && header.imagetype != IT_UNCOMPRESSED)
  {
    fclose(f);
    return;
  }

  if (header.bits != 24 && header.bits != 32)
  {
    fclose(f);
    return;
  }

  int bufferSize = fileLen - sizeof(header) - header.identsize;
  char * pBuffer = new char[bufferSize];
  fread(pBuffer, 1, bufferSize, f);
  fclose(f);

  width = header.width;
  height = header.height;
  bpp = header.bits;
  char * pOutBuffer = new char[header.width * header.height * header.bits / 8];
  
  switch (header.imagetype)
  {
  case IT_UNCOMPRESSED:
    LoadUncompressedImage(pOutBuffer, pBuffer, &header);
    break;
  case IT_COMPRESSED:
    LoadCompressedImage(pOutBuffer, pBuffer, &header);
    break;
  }
  
  delete[] pBuffer;
  textureBuffer = pOutBuffer;
}


tgaLoader::~tgaLoader()
{
}
