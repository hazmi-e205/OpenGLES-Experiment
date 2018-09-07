#include <jni.h>
#include "Implement.h"
#include "Speak.h"

extern "C"
JNIEXPORT void JNICALL
Java_id_hazmi_ogles_JNIBridge_native_1init(JNIEnv *env, jclass type) {
    native_init();
}

extern "C"
JNIEXPORT void JNICALL
Java_id_hazmi_ogles_JNIBridge_ogl_1init(JNIEnv *env, jclass type, jint width, jint height) {
    native_gl_init(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_id_hazmi_ogles_JNIBridge_ogl_1draw(JNIEnv *env, jclass type) {
    native_gl_draw();
}

extern "C"
JNIEXPORT void JNICALL
Java_id_hazmi_ogles_JNIBridge_getDataDirectory(JNIEnv *env, jclass type, jstring dataDir_) {
    const char *dataDir = env->GetStringUTFChars(dataDir_, 0);
    Problem("%s", dataDir);
    setDataDir(dataDir);
    env->ReleaseStringUTFChars(dataDir_, dataDir);
}

extern "C"
JNIEXPORT void JNICALL
Java_id_hazmi_ogles_JNIBridge_setAsset(JNIEnv *env, jclass type, jobject assetMgr) {
    setAssetMgr(AAssetManager_fromJava(env,assetMgr));
}