#pragma once

#include "PlatformDefine.h"

#if defined (VisualStudio) || defined (CodeBlocks)
#include "GL/glew.h"

#elif defined (AndroidStudio)
#include <GLES2/gl2.h>

#endif // (VisualStudio)

