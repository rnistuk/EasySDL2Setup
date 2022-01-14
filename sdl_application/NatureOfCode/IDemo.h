#pragma once
#include "../SDL2Wrapper/SDL2Renderer.h"

class IDemo {
public:
    virtual void setup(DZS::SDL2Renderer& r) = 0;
    virtual void draw(DZS::SDL2Renderer& r) = 0;
    virtual void step() = 0;
};
