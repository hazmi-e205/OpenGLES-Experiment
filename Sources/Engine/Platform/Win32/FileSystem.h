//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_FILESYSTEM_H
#define OGLES_FILESYSTEM_H

#include <stdio.h>
#include <string>

class FileSystem {
private:
    static FileSystem *MyFS;
    std::string ExternalAppDir;

public:
    static FileSystem *Get();
    static void Shutdown();
    void SetAppDirectory(const char* appDir);
    const char* GetAppDirectory();
    FILE* GetFile(const char* Filename, const char* mode);

    FileSystem();
    ~FileSystem();
};


#endif //OGLES_FILESYSTEM_H
