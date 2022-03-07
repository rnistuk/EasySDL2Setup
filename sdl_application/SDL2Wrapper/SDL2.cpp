#include "SDL2.h"
#include <SDL2/SDL.h>

namespace DZS {
    SDL2::SDL2() {
        SDL_Init(SDL_INIT_EVERYTHING);
    }

    SDL2::~SDL2() {
        SDL_Quit();
    }

    SDL2Window *SDL2::createWindow() {
        return new SDL2Window("title");
    }


}
