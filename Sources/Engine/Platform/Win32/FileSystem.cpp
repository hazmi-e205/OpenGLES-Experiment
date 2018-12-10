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
    
    //read from asset directory
    if (myFile == NULL) {
        std::string file_src = ExternalAppDir + "/" + filename;
        myFile = fopen(file_src.c_str(), mode);
        if (myFile == nullptr) {
            Problem("Load External: %s is not available files directory", filename);
        }
    }

    return myFile;
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

void FileSystem::Shutdown()
{
  delete MyFS;
}
