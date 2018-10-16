#pragma once

class tgaLoader
{
private:
#pragma pack(push,x1)					// Byte alignment (8-bit)
#pragma pack(1)
  typedef struct
  {
    unsigned char  identsize;			// size of ID field that follows 18 byte header (0 usually)
    unsigned char  colourmaptype;		// type of colour map 0=none, 1=has palette
    unsigned char  imagetype;			// type of image 2=rgb uncompressed, 10 - rgb rle compressed

    short colourmapstart;				// first colour map entry in palette
    short colourmaplength;				// number of colours in palette
    unsigned char  colourmapbits;		// number of bits per palette entry 15,16,24,32

    short xstart;						// image x origin
    short ystart;						// image y origin
    short width;						// image width in pixels
    short height;						// image height in pixels
    unsigned char  bits;				// image bits per pixel 24,32
    unsigned char  descriptor;			// image descriptor bits (vh flip bits)
                                    // pixel data follows header
  } TGA_HEADER;
#pragma pack(pop,x1)

  enum tgaType
  {
    IT_COMPRESSED = 10,
    IT_UNCOMPRESSED = 2
  };

  void LoadCompressedImage(char* pDest, char * pSrc, TGA_HEADER * pHeader);
  void LoadUncompressedImage(char* pDest, char * pSrc, TGA_HEADER * pHeader);
  short width, height;
  unsigned char  bpp;
  char * textureBuffer;
  
public:
  char* getTexture() { return textureBuffer; }
  short getWidth() { return width; };
  short getHeight() { return height; };
  unsigned char  getBpp() { return bpp; };
  tgaLoader(const char * file_tga);
  ~tgaLoader();
};

