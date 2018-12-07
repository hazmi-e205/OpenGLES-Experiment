//
// Created by Hazmi Amalul Arifin on 08/12/2018.
//

#ifndef OGLES_ENGINE_H
#define OGLES_ENGINE_H

#define MyEngine Engine::Get()

class Engine {
private:
    Engine *myEngine;

public:
    void Create();
    bool isValid();
    Engine *Get();

};


#endif //OGLES_ENGINE_H
