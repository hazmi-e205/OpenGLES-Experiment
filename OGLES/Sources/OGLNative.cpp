//
// Created by hazmi.arifin on 5/12/2018.
//

#include "stdafx.h"
#include "OGLNative.h"
#include "Speak.h"
#include "Implement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#if defined (AndroidStudio)
#include "AssetNative.h"
#include "Implement.h"
#include <jni.h>
#endif

GLuint loadShader(GLenum shaderType, const char* pSource) {
    Say("Source:");
    Say(pSource);
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = new char[infoLen];
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    Problem("Could not compile shader %d:\n%s\n", shaderType, buf);
                    delete []buf;
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource) {
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
    if (!vertexShader) {
        return 0;
    }

    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
    if (!pixelShader) {
        return 0;
    }

    GLuint program = glCreateProgram();
    if (program) {
        glAttachShader(program, vertexShader);
        checkGlError("glAttachShader");
        glAttachShader(program, pixelShader);
        checkGlError("glAttachShader");
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE) {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength) {
                char* buf = new char[bufLength];
                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    Problem("Could not link program:\n%s\n", buf);
                    delete []buf;
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    Speak("GL %s = %s\n", name, v);
}

void checkGlError(const char* op) {
    for (GLint error = glGetError(); error; error = glGetError()) {
        Speak("after %s() glError (0x%x)\n", op, error);
    }
}

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
const int IT_COMPRESSED = 10;
const int IT_UNCOMPRESSED = 2;

void LoadCompressedImage( char* pDest, char * pSrc, TGA_HEADER * pHeader )
{
    int w = pHeader->width;
    int h = pHeader->height;
    int rowSize = w * pHeader->bits / 8;
    bool bInverted = ( (pHeader->descriptor & (1 << 5)) != 0 );
    char * pDestPtr = bInverted ? pDest + (h + 1) * rowSize : pDest;
    int countPixels = 0;
    int nPixels = w * h;

    while( nPixels > countPixels )
    {
        unsigned char chunk = *pSrc ++;
        if ( chunk < 128 )
        {
            int chunkSize = chunk + 1;
            for ( int i = 0; i < chunkSize; i ++ )
            {
                if ( bInverted && (countPixels % w) == 0 )
                    pDestPtr -= 2 * rowSize;
                *pDestPtr ++ = pSrc[2];
                *pDestPtr ++ = pSrc[1];
                *pDestPtr ++ = pSrc[0];
                pSrc += 3;
                if ( pHeader->bits != 24 )
                    *pDestPtr ++ = *pSrc ++;
                countPixels ++;
            }
        }
        else
        {
            int chunkSize = chunk - 127;
            for ( int i = 0; i < chunkSize; i ++ )
            {
                if ( bInverted && (countPixels % w) == 0 )
                    pDestPtr -= 2 * rowSize;
                *pDestPtr ++ = pSrc[2];
                *pDestPtr ++ = pSrc[1];
                *pDestPtr ++ = pSrc[0];
                if ( pHeader->bits != 24 )
                    *pDestPtr ++ = pSrc[3];
                countPixels ++;
            }
            pSrc += (pHeader->bits >> 3);
        }
    }
}

void LoadUncompressedImage( char* pDest, char * pSrc, TGA_HEADER * pHeader )
{
    int w = pHeader->width;
    int h = pHeader->height;
    int rowSize = w * pHeader->bits / 8;
    bool bInverted = ( (pHeader->descriptor & (1 << 5)) != 0 );
    for ( int i = 0; i < h; i ++ )
    {
        char * pSrcRow = pSrc +
                         ( bInverted ? ( h - i - 1 ) * rowSize : i * rowSize );
        if ( pHeader->bits == 24 )
        {
            for ( int j = 0; j < w; j ++ )
            {
                *pDest ++ = pSrcRow[2];
                *pDest ++ = pSrcRow[1];
                *pDest ++ = pSrcRow[0];
                pSrcRow += 3;
            }
        }
        else
        {
            for ( int j = 0; j < w; j ++ )
            {
                *pDest ++ = pSrcRow[2];
                *pDest ++ = pSrcRow[1];
                *pDest ++ = pSrcRow[0];
                *pDest ++ = pSrcRow[3];
                pSrcRow += 4;
            }
        }
    }
}


char * LoadTGA( const char * szFileName, int * width, int * height, int * bpp )
{
    FILE* f = NULL;
#if defined (AndroidStudio)
    f = asset_fopen(szFileName,"r");
    if (f == NULL) {
        Problem("Load Internal: Model Texture (.tga) is not available on asset");
    }
#endif
    if (f == NULL) {
        std::string tga_src = getDataDir() + "/" + szFileName;
        f = fopen(tga_src.c_str(), "r");
        if (f == NULL) {
            Problem("Load External: Model Texture (.tga) is not available files directory");
            return NULL;
        }
    }

    TGA_HEADER header;
    fread( &header, sizeof(header), 1, f );

    fseek( f, 0, SEEK_END );
    int fileLen = ftell( f );
    fseek( f, sizeof( header ) + header.identsize, SEEK_SET );

    if ( header.imagetype != IT_COMPRESSED && header.imagetype != IT_UNCOMPRESSED )
    {
        fclose( f );
        return NULL;
    }

    if ( header.bits != 24 && header.bits != 32 )
    {
        fclose( f );
        return NULL;
    }

    int bufferSize = fileLen - sizeof( header ) - header.identsize;
    char * pBuffer = new char[bufferSize];
    fread( pBuffer, 1, bufferSize, f );
    fclose( f );

    *width = header.width;
    *height = header.height;
    *bpp = header.bits;
    char * pOutBuffer = new char[ header.width * header.height * header.bits / 8 ];

    switch( header.imagetype )
    {
        case IT_UNCOMPRESSED:
            LoadUncompressedImage( pOutBuffer, pBuffer, &header );
            break;
        case IT_COMPRESSED:
            LoadCompressedImage( pOutBuffer, pBuffer, &header );
            break;
    }

    delete[] pBuffer;
    return pOutBuffer;
}
