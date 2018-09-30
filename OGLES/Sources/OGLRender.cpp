//
// Created by hazmi.arifin on 5/26/2018.
//

#include "stdafx.h"
#include <string>
#include "OGLNative.h"
#include "OGLRender.h"
#include "Speak.h"
#include "Model.h"
#include "Implement.h"

#if defined (AndroidStudio)
#include <GLES2/gl2.h>
#elif defined (VisualStudio)
#include "GL/glew.h"
#endif

Model *women1, *women2;
std::string namaNfg1, namaTga1;
std::string namaNfg2, namaTga2;
Vector3 transLt1(-0.27f, 0.0f, 0.0f);
Vector3 transLt2(0.27f, 0.0f, 0.0f);
float scale1 = 0.4f;
float scale2 = 0.4f;

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

	women1 = new Model();
    women1->InitModel(namaNfg1.c_str(), namaTga1.c_str());
    women1->translation(transLt1);
    women1->scale(scale1);

    namaNfg2 = "Woman2.nfg";
    namaTga2 = "Woman2.tga";
	women2 = new Model();
    women2->InitModel(namaNfg2.c_str(), namaTga2.c_str());
    women2->translation(transLt2);
    women2->scale(scale2);

    return true;
}


void renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    women1->translation(transLt1);
    women1->scale(scale1);
    women1->drawModel();

    women2->translation(transLt2);
    women2->scale(scale2);
    women2->drawModel();

    static float rot = 0.0f;
    women1->rotationY(rot);
    women2->rotationY(-rot);
    rot += 0.01f;
}

