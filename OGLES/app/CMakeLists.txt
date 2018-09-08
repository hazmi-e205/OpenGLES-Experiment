# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             JNIBridge

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/JNIBridge.cpp
             src/main/cpp/AssetNative.cpp
             src/main/cpp/Implement.cpp
             src/main/cpp/OGLNative.cpp
             src/main/cpp/OGLShader.cpp
             src/main/cpp/OGLRender.cpp
             src/main/cpp/Vertex.cpp
             src/main/cpp/Mystic.cpp
             src/main/cpp/Model.cpp
             src/main/cpp/Speak.cpp
             )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       JNIBridge
                       EGL
                       GLESv2
                       log
                       android
                       )