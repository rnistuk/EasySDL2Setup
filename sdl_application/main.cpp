#include <iostream>
#include "NatureOfCode/Walker.h"
#include "NatureOfCode/IDemo.h"
#include "NatureOfCode/Histogram.h"
#include "SDL2Wrapper/SDL2.h"

bool done = false;

void handleEvents(SDL_Event &event);

void clearWindow(DZS::SDL2Renderer *r);

int main (int argc, char *argv[], char *envp[])
{
    DZS::SDL2 sdl;
    if (sdl.isInitialized())
    {
        SDL_Event event;
        // Do your set up in the setup function.
        auto w {sdl.createWindow()};
        auto r = w->renderer();
        IDemo* demo = new Walker();

        demo->setup(*r);
        while (!done) {
            clearWindow(r);

            // Draw your scene in the draw function
            demo->draw(*r);
            demo->step();

            // loop cleanup
            r->present();
            handleEvents(event);
        }
    }

    // Clean up and quit SDL2
    return 0;
}

void clearWindow(DZS::SDL2Renderer *r) {
    r->set_draw_color(0, 0, 0, 255);
    r->clear();
}

void handleEvents(SDL_Event &event) {// The only event we catch is the quit event.
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            done = SDL_TRUE;
        }
    }
}
