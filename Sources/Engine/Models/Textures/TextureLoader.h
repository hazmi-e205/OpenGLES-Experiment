#pragma once
class TextureLoader
{
public:
	unsigned char* getTexture() { return textureBuffer; }
	short getWidth() { return width; };
	short getHeight() { return height; };

	TextureLoader(const char * TextureFileName);
	~TextureLoader();

private:
	int width, height, channels;
	unsigned char *textureBuffer;
};

