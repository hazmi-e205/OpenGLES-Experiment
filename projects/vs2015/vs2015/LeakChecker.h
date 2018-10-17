#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#define LeakCheck() _CrtDumpMemoryLeaks()