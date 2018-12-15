//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_FILESYSTEM_H
#define OGLES_FILESYSTEM_H

#include <stdio.h>
#include <string>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

class FileSystem {
private:
    static FileSystem *MyFS;
    std::string ExternalAppDir;
    AAssetManager* assetManagerPtr;
    static int asset_read(void* cookie, char* buf, int size);
    static int asset_write(void* cookie, const char* buf, int size);
    static fpos_t asset_seek(void* cookie, fpos_t offset, int whence);
    static int asset_close(void* cookie);

public:
    static FileSystem *Get();
    static void Destroy();
    void SetAppDirectory(const char* appDir);
    const char* GetAppDirectory();
    void setAssetManager (AAssetManager* assetPtr);
    FILE* asset_fopen(const char* fname, const char* mode);
    FILE* GetFile(const char* Filename, const char* mode);

    FileSystem();
    ~FileSystem();
};


#endif //OGLES_FILESYSTEM_H
