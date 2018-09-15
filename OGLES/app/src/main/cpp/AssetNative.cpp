//
// Created by hazmi.arifin on 6/5/2018.
//

#include "AssetNative.h"
#include "Implement.h"
#include "Speak.h"

static int asset_read(void* cookie, char* buf, int size) {
    return AAsset_read((AAsset*)cookie, buf, size);
}

static int asset_write(void* cookie, const char* buf, int size) {
    Problem("Asset can't be written");
    return 0; // can't provide write access to the apk
}

static fpos_t asset_seek(void* cookie, fpos_t offset, int whence) {
    return AAsset_seek((AAsset*)cookie, offset, whence);
}

static int asset_close(void* cookie) {
    AAsset_close((AAsset*)cookie);
    return 0;
}

// must be established by someone else...
/*AAssetManager* android_asset_manager = NULL;
void android_fopen_set_asset_manager(AAssetManager* manager) {
    android_asset_manager = manager;
}*/

FILE* asset_fopen(const char* fname, const char* mode) {
    if(mode[0] == 'w') return NULL;

    AAsset* asset = AAssetManager_open(getAssetMgr(), fname, 0);
    if(!asset) return NULL;

    return funopen(asset, asset_read, asset_write, asset_seek, asset_close);
}