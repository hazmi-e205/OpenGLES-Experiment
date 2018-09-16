//
// Created by hazmi.arifin on 5/28/2018.
//

#include "Speak.h"

#if defined (QtProject)
#include <QDebug>
#include <cstdio>

void Speak(const char* format, ...)
{
    va_list vl;
    char SpeakBuffer [300];
    sprintf(SpeakBuffer, format, vl);
    qDebug() << LOG_TAG << "Speak ==>" << SpeakBuffer;
}

void Problem(const char* format, ...)
{
    va_list vl;
    char SpeakBuffer [300];
    sprintf(SpeakBuffer, format, vl);
    qDebug() << LOG_TAG << "Problem ==>" << SpeakBuffer;
}

void Say(const char* format, ...)
{
    va_list vl;
    char SpeakBuffer [300];
    sprintf(SpeakBuffer, format, vl);
    qDebug() << LOG_TAG << "Say ==>" << SpeakBuffer;
}

#endif
