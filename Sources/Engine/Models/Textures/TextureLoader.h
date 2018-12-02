#pragma once

class TextureLoader
{
public:
	enum TextureMode
	{
		LOAD_AUTO = 0,
		LOAD_L = 1,
		LOAD_LA = 2,
		LOAD_RGB = 3,
		LOAD_RGBA = 4
	};
	unsigned char* getTexture() { return textureBuffer; }
	short getWidth() { return width; };
	short getHeight() { return height; };

	TextureLoader(const char * TextureFileName, TextureMode textureMode = LOAD_AUTO);
	~TextureLoader();

private:
	int width, height, channels;
	unsigned char *textureBuffer;
};

