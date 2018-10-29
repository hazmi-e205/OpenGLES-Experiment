#pragma once

class pngLoader
{
private:
  unsigned int width, height;
  unsigned char *textureBuffer;
  
public:
  unsigned char* getTexture() { return textureBuffer; }
  short getWidth() { return width; };
  short getHeight() { return height; };
  pngLoader(const char * file_png);
  ~pngLoader();
};

