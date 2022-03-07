#pragma once

#include <functional>
#include <memory>
#include <SDL2/SDL.h>
#include <string>

#include "SDL2Renderer.h"

namespace DZS {
    struct SDLWindowDestroyer {
        void operator()(SDL_Window *w) const {
            SDL_DestroyWindow(w);
        }
    };

    class SDL2Window {
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> wnd;

        SDL_Window *window() { return this->wnd.get(); }

        SDL_Renderer *getRenderer() {
            auto r{SDL_GetRenderer(this->window())};
            if (r) {
                return r;
            }

            std::cerr << "SDL_GetRenderer failed trying SDL_CreateRenderer[" << SDL_GetError() << "]\n";
            r = SDL_CreateRenderer(this->window(), -1, 0);

            if (r) {
                return r;
            }
            std::cerr << "SDL_CreateRenderer failed[" << SDL_GetError() << "]\n";
            return nullptr;
        }

    public:
        explicit SDL2Window(const std::string &title) : wnd(nullptr, SDL_DestroyWindow) {
            // SDL_DestroyWindow
            this->wnd.reset(SDL_CreateWindow(
                    title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0));
        }

        std::string title() {
            return SDL_GetWindowTitle(this->window());
        }

        int width() {
            int w{0};
            SDL_GetWindowSize(this->window(), &w, nullptr);
            return w;
        }

        int height() {
            int h{0};
            SDL_GetWindowSize(this->window(), nullptr, &h);
            return h;
        }

        SDL2Renderer *renderer() {
            return new SDL2Renderer(this->getRenderer());
        }
    };
}
