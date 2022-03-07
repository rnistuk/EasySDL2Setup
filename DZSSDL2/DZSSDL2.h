#pragma once

#include "DZSWindow.h"

namespace DZS {
    class SDL2 {public:
        SDL2();

        ~SDL2();

        SDL2Window *createWindow();

        bool isInitialized() {
            return SDL_INIT_EVERYTHING == SDL_WasInit(SDL_INIT_EVERYTHING);
        }
    };
}
