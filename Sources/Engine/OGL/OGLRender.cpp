//
// Created by hazmi.arifin on 5/26/2018.
//

#include "OGLAdapter.h"
#include "OGLNative.h"
#include "OGLRender.h"
#include "Engine/Utils/Speak.h"
#include "Engine/Models/ModelType.h"
#include "Engine/Models/ModelType1.h"
#include "Engine/Models/ModelType2.h"
#include "Implement.h"

ModelType *women1, *women2;
const char *namaNfg1, *namaTga1;
const char *namaObj1, *namaPng1;
Vector3 transLt1(-0.27f, 0.0f, 0.0f);
Vector3 transLt2(0.27f, 0.0f, 0.0f);
float scale1 = 0.4f;
float scale2 = 0.11f;

bool setupGraphics(int w, int h) {
#if defined (AndroidStudio)
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);
#endif

    Speak("setupGraphics(%d, %d)", w, h);
    glViewport(0, 0, w, h);
    checkGlError("glViewport");
    glClearColor(1.0f,1.0f,1.0f,1.0f);

    namaNfg1 = "Woman1.nfg";
    namaTga1 = "Woman1.tga";
    
    women1 = new ModelType1(namaNfg1, namaTga1);
    women1->translation(transLt1);
    women1->scale(scale1);

    namaObj1 = "anime_charcter.obj";
    namaPng1 = "anime_charcter.png";
    
    women2 = new ModelType2(namaObj1, namaPng1);
    women2->translation(transLt2);
    women2->scale(scale2);

    return true;
}


void renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    women1->translation(transLt1);
    women1->scale(scale1);
    women1->draw();

    women2->translation(transLt2);
    women2->scale(scale2);
    women2->draw();

    static float rot = 0.0f;
    women1->rotationY(rot);
    women2->rotationY(-rot);
    rot += 0.01f;
}

void cleanup()
{
  delete women1;
  delete women2;
}

