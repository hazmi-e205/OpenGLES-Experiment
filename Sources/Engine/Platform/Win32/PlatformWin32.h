//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_PLATFORM_WIN32_H
#define OGLES_PLATFORM_WIN32_H

class Platform {
private:
  static Platform *MyPlatform;

public:
  static Platform *Get();
  static void Destroy();

  Platform();
  ~Platform();
};

#endif //OGLES_PLATFORM_WIN32_H
