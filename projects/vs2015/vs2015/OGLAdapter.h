#pragma once

#include "PlatformDefine.h"

#if defined (VisualStudio) || defined (CodeBlocks)
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#elif defined (AndroidStudio)
#include <GLES2/gl2.h>

#endif // (VisualStudio)

