//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_PLATFORM_H
#define OGLES_PLATFORM_H

class Platform {
public:
    virtual void Create();
    virtual bool isValid();
    static Platform *Get();
};


#endif //OGLES_PLATFORM_H
