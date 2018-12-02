#include "TextureLoader.h"
#include "SOIL/SOIL.h"
#include "Engine/Utils/Speak.h"
#include "Engine/Implement.h"
#include "PlatformDefine.h"
#include <string>

TextureLoader::TextureLoader(const char * TextureFileName, TextureMode textureMode)
{
	textureBuffer = SOIL_load_image(TextureFileName, &width, &height, &channels, textureMode);
	if (nullptr == textureBuffer) {
		Problem("Texture Null Jancok!");
	}
}


TextureLoader::~TextureLoader()
{
	SOIL_free_image_data(textureBuffer);
}
