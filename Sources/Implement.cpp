//
// Created by hazmi.arifin on 5/2/2018.
//

#include <Engine/Utils/Speak.h>
#include "Implement.h"
#include "Engine/Engine.h"
#include "Engine/OGL/OGLRender.h"

int w_screen, h_screen;

void native_init()
{
    while (!Engine::isValid())
    {
        Engine::Create();
    }
    Say("Engine Init !");

    auto a1 = MyEngine->GetPlatform();
    while (!a1)
    {
        //Engine::Create();
    }
    Say("Platform Init !");

    auto a2 = a1->GetFS();
    while (!a2)
    {
        //Engine::Create();
    }
    Say("FS Init !");
}

void native_gl_init(int width, int height)
{
    w_screen = width;
    h_screen = height;
    setupGraphics(width,height);
}

void native_gl_draw()
{
    renderFrame();
}

void native_cleanup()
{
  cleanup();
}

void getScreen(int &width, int &height)
{
    width = w_screen;
    height = h_screen;
}

float getAspectRatio()
{
    return (float) w_screen / (float) h_screen;
}
