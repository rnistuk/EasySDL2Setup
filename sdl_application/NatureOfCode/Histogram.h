#pragma once
#include "IDemo.h"
#include "../SDL2Wrapper/SDL2Renderer.h"
#include <cstdlib>
#include <locale>
#include <array>

class Histogram : public IDemo {
public:
    Histogram() {
        std::srand(std::time(0));
        std::for_each(counts.begin(), counts.end(), [](auto &c) {c = 0;});
    }

    void setup(DZS::SDL2Renderer& r) {
    }

    void draw(DZS::SDL2Renderer& r) {
        r.set_draw_color(255,2,5,255);
        const size_t w = 640/counts.size();
        const size_t h{480};

        for( size_t x{0}; x < counts.size(); ++x ) {
            const auto c{counts[x]/2};
            r.draw_rect(x * w, h-c,w-1,c);
        }
    }

    void step() {
        const auto r = std::rand() % counts.size();
        ++counts[r];
    }

private:
    std::array<uint, 20> counts;
};
