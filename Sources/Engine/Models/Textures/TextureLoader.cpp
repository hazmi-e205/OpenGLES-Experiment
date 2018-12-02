#include "TextureLoader.h"
#include "SOIL/SOIL.h"
#include "Engine/Utils/Speak.h"
#include "Engine/Implement.h"
#include "PlatformDefine.h"
#include <string>

TextureLoader::TextureLoader(const char * TextureFileName)
{
	/*
	FILE* f = NULL;
#if defined (AndroidStudio)
	f = asset_fopen(file_tga, "r");
	if (f == NULL) {
		Problem("Load Internal: Model Texture (.tga) is not available on asset");
	}
#endif
	if (f == NULL) {
		std::string tga_src = std::string(getDataDir()) + "/" + file_tga;
		f = fopen(tga_src.c_str(), "r");
		if (f == NULL) {
			Problem("Load External: %s", tga_src.c_str());
			Problem("Load External: Model Texture (.tga) is not available files directory");
			return;
		}
	}
	*/

	std::string texture_src = std::string(getDataDir()) + "/" + TextureFileName;
	textureBuffer = SOIL_load_image(texture_src.c_str(), &width, &height, &channels, SOIL_LOAD_RGB);
	if (nullptr == textureBuffer) {
		Problem("Texture Null Jancok!");
	}
}


TextureLoader::~TextureLoader()
{
	SOIL_free_image_data(textureBuffer);
}
