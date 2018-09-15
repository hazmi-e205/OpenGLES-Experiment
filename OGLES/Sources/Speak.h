//
// Created by hazmi.arifin on 5/28/2018.
//

#ifndef OGLES_SPEAK_H
#define OGLES_SPEAK_H

#include <android/log.h>

#define  LOG_TAG    "HazmiOGL"
#define  Speak(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  Problem(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  Say(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)

#endif //OGLES_SPEAK_H
