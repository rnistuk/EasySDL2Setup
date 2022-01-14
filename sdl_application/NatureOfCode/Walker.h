#pragma once
#include "../SDL2Wrapper/SDL2Renderer.h"
#include "IDemo.h"
#include <cstdlib>
#include <vector>
#include <array>

class Walker : public IDemo {
public:
    Walker() : x(0), y(0) {
        std::srand(std::time(0));
    }

    void setup(DZS::SDL2Renderer& r) {
        this->x = r.width() / 2 ;
        this->y = r.height() / 2 ;
        pts.push_back(std::pair<int,int>(this->x, this->y));
    }

    void draw(DZS::SDL2Renderer& r) {
        r.set_draw_color(255,2,5,255);
        std::for_each(pts.begin(), pts.end(),  [&](auto pt)  {
            r.draw_circle(pt.first, pt.second, 1);
        });
    }

    void step() {
        const int d{3};
        int dx = d * (std::rand() % 3 - 1);
        int dy = d * (std::rand() % 3 - 1);
        x += dx;
        y += dy;

        if(pts.size()>500) {
            pts.pop_back();
        }
        pts.insert(pts.begin(), std::pair<int,int>(x, y));
    }

private:
    int x;
    int y;
    std::vector<std::pair<int, int>> pts;
};
