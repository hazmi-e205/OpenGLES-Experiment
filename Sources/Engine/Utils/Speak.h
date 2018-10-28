//
// Created by hazmi.arifin on 5/28/2018.
//

#ifndef OGLES_SPEAK_H
#define OGLES_SPEAK_H
#include "PlatformDefine.h"

#if defined (AndroidStudio)
#include <android/log.h>
#define LOG_TAG "HazmiOGL"

#define  Speak(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  Problem(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  Say(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)

#elif defined (VisualStudio) || defined (CodeBlocks)
#include <stdio.h>

#define  Speak(myformat, ...)     printf("Speak   ==> " myformat "\n", __VA_ARGS__)
#define  Problem(myformat, ...)   printf("Problem ==> " myformat "\n", __VA_ARGS__)
#define  Say(myformat, ...)       printf("Say     ==> " myformat "\n", __VA_ARGS__)

#endif

#endif //OGLES_SPEAK_H
