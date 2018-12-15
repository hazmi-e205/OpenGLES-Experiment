//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#include "FileSystem.h"
#include <Engine/Utils/Speak.h>

FileSystem *FileSystem::MyFS;

void FileSystem::SetAppDirectory(const char *appDir) {
    ExternalAppDir = appDir;
}

const char *FileSystem::GetAppDirectory() {
    return ExternalAppDir.c_str();
}

FILE *FileSystem::GetFile(const char *filename, const char* mode) {
    FILE *myFile = nullptr;

    //read from asset first
    myFile = asset_fopen(filename, mode);
    if (myFile == NULL) {
        Problem("Load Internal: %s is not available on asset", filename);
    }

    //read from app folder if not found on asset
    if (myFile == NULL) {
        std::string file_src = ExternalAppDir + "/" + filename;
        myFile = fopen(file_src.c_str(), mode);
        if (myFile == nullptr) {
            Problem("Load External: %s is not available files directory", filename);
        }
    }

    return myFile;
}

FILE *FileSystem::asset_fopen(const char *fname, const char *mode) {
    if(mode[0] == 'w') return NULL;

    AAsset* asset = AAssetManager_open(assetManagerPtr, fname, 0);
    if(!asset) {
        Problem("AssetManager Failed !");
        return NULL;
    }

    return funopen(asset, asset_read, asset_write, asset_seek, asset_close);
}

int FileSystem::asset_read(void *cookie, char *buf, int size) {
    return AAsset_read((AAsset*)cookie, buf, size);
}

int FileSystem::asset_write(void *cookie, const char *buf, int size) {
    Problem("Asset can't be written");
    return 0; // can't provide write access to the apk
}

fpos_t FileSystem::asset_seek(void *cookie, fpos_t offset, int whence) {
    return AAsset_seek((AAsset*)cookie, offset, whence);
}

int FileSystem::asset_close(void *cookie) {
    AAsset_close((AAsset*)cookie);
    return 0;
}

void FileSystem::setAssetManager(AAssetManager *assetPtr) {
    assetManagerPtr = assetPtr;
}

FileSystem::FileSystem() {

}

FileSystem::~FileSystem() {

}

FileSystem *FileSystem::Get() {
    Problem("FileSystem::Get()");
    while (!MyFS) {
        MyFS = new FileSystem();
    }
    Problem("FileSystem::Get() Ok!");
    return MyFS;
}

void FileSystem::Destroy()
{
  delete MyFS;
}