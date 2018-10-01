//
// Created by hazmi.arifin on 5/28/2018.
//

#include "stdafx.h"
#include "Speak.h"

#if defined (VisualStudio) || defined (CodeBlocks)
#include <stdio.h>
#include <stdarg.h>
const char* LOG_TAG = "HazmiOGL";

void Speak(const char* format, ...)
{
    va_list vl;
	va_start(vl, format);
	printf("%s", LOG_TAG);
	printf(" :: Speak ==> ");
	printf(format, vl);
	printf("\n");
}

void Problem(const char* format, ...)
{
	va_list vl;
	va_start(vl, format);
	printf("%s", LOG_TAG);
	printf(" :: Problem ==> ");
	printf(format, vl);
	printf("\n");
}

void Say(const char* format, ...)
{
	va_list vl;
	va_start(vl, format);
	printf("%s", LOG_TAG);
	printf(" :: Say ==> ");
	printf(format, vl);
	printf("\n");
}

#endif
