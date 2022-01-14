#pragma once
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>

namespace DZS {

    class SDL2Renderer {
    public:
        explicit SDL2Renderer(SDL_Renderer *r) : rndr(nullptr, &SDL_DestroyRenderer) {
            this->rndr.reset(r);
        }

        void clear() {
            SDL_RenderClear(this->renderer());
        }

        int draw_line(int x1, int y1, int x2, int y2) {
            return SDL_RenderDrawLine(this->renderer()
                    , x1, y1
                    , x2, y2);
        }

        int draw_point(int x, int y) {
            return SDL_RenderDrawPoint(this->renderer(), x, y);
        }

        int draw_point(float x, float y) {
            return SDL_RenderDrawPointF(this->renderer(), x, y);
        }

        int draw_circle(int xc, int yc, int r) {
            int x = 0;
            int y = r;
            int d = 3 - (2 * r);
            this->displayBresenhmCircle(xc, yc, x, y);
            while (x<=y) {
                x++;
                d = d<0 ? d + (4*x) + 6 :  d + 4 * ( x - y--) + 10;
                this->displayBresenhmCircle(xc, yc, x, y);
            }


            return 0;
        }

        int draw_rect(int x, int y, int w, int h) {
            const SDL_Rect r{x, y, w, h};
            return SDL_RenderDrawRect(this->renderer(), &r);
        }

        void present() {
            SDL_RenderPresent(this->renderer());
        }

        void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 ) {
            SDL_SetRenderDrawColor(this->renderer(), r, g, b, a);
        }

        int width() {
            int w,h;
            SDL_GetRendererOutputSize(this->renderer(),&w, &h);
            return w;
        }

        int height() {
            int w,h;
            SDL_GetRendererOutputSize(this->renderer(),&w, &h);
            return h;
        }


        void info() {
            SDL_RendererInfo ri;
            SDL_RendererInfo ri0;

            SDL_GetRendererInfo(this->renderer(), &ri);
            SDL_GetRenderDriverInfo(0, &ri0);

            int w,h;
            SDL_GetRendererOutputSize(this->renderer(),&w, &h);


            std::cout << "width:" << ri.max_texture_width << "\n";
            std::cout << "height:" << ri.max_texture_height << "\n";

        }

    private:
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> rndr;
        SDL_Renderer* renderer() {
            return rndr.get();
        }
        uint ptSize{0};

        template<typename T>
        void displayBresenhmCircle(T xc_, T yc_, T x, T y)
        {
            SDL_RenderDrawPoint(this->renderer(),xc_+x, yc_+y);
            SDL_RenderDrawPoint(this->renderer(),xc_-x, yc_+y);
            SDL_RenderDrawPoint(this->renderer(),xc_+x, yc_-y);
            SDL_RenderDrawPoint(this->renderer(),xc_-x, yc_-y);
            SDL_RenderDrawPoint(this->renderer(),xc_+y, yc_+x);
            SDL_RenderDrawPoint(this->renderer(),xc_-y, yc_+x);
            SDL_RenderDrawPoint(this->renderer(),xc_+y, yc_-x);
            SDL_RenderDrawPoint(this->renderer(),xc_-y, yc_-x);
        }

    };
}
