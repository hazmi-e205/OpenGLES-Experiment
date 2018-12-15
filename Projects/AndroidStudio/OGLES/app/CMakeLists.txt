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
             ../../../../Sources/Implement.cpp
             ../../../../Sources/Engine/Engine.cpp
             ../../../../Sources/Engine/Platform/Android/FileSystem.cpp
             ../../../../Sources/Engine/Platform/Android/Implement.cpp
             ../../../../Sources/Engine/Platform/Android/PlatformAndroid.cpp
             ../../../../Sources/Engine/Utils/Mystic.cpp
             ../../../../Sources/Engine/Utils/Speak.cpp
             ../../../../Sources/Engine/OGL/OGLNative.cpp
             ../../../../Sources/Engine/OGL/OGLShader.cpp
             ../../../../Sources/Engine/OGL/OGLRender.cpp
             ../../../../Sources/Engine/Models/Resources/Vertex.cpp
			 ../../../../Sources/Engine/Models/Resources/nfgReader.cpp
             ../../../../Sources/Engine/Models/Resources/objReader.cpp
			 ../../../../Sources/Engine/Models/Textures/TextureLoader.cpp
			 ../../../../Sources/Engine/Models/Textures/SOIL/SOIL.c
			 ../../../../Sources/Engine/Models/Textures/SOIL/image_DXT.c
			 ../../../../Sources/Engine/Models/Textures/SOIL/image_helper.c
			 ../../../../Sources/Engine/Models/Textures/SOIL/stb_image_aug.cpp
             ../../../../Sources/Engine/Models/ModelType.cpp
             ../../../../Sources/Engine/Models/ModelType1.cpp
             ../../../../Sources/Engine/Models/ModelType2.cpp
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

include_directories ( # Here directory you need
                      src/main/cpp/
                      ../../../../Sources/
                    )