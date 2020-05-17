#include <iostream>
#include <SDL2/SDL.h>

void
setup(SDL_Window *window, SDL_Renderer *renderer);

void
draw(SDL_Window *window, SDL_Renderer *renderer);

SDL_Color
wavelength_to_rgb(float wavelength, float gamma = 0.2);

void draw_rainbow(SDL_Renderer *renderer, int w, int h);

int
main (int argc, char *argv[], char *envp[]) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    if (0==SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer)) {
        SDL_Event event;
        bool done = false;

        // Do your set up in the setup function.
        setup(window, renderer);

        while (!done) {
            // Draw your scene in the draw function
            draw(window, renderer);

            SDL_RenderPresent(renderer);

            // The only event we catch is the quit event.
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    done = SDL_TRUE;
                }
            }
        }
    }

    // Clean up and quit SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// draw and setup could be encapsulated in a class
void
setup(SDL_Window *window, SDL_Renderer *renderer) {
    // scene setup goes here
}

void
draw(SDL_Window *window, SDL_Renderer *renderer) {
    // draw your scene here... replace the following.
    SDL_SetRenderDrawColor(renderer, 25, 188, 255, 200);
    SDL_RenderClear(renderer);

    int w{0};
    int h{0};
    SDL_GetWindowSize(window, &w, &h);

    draw_rainbow(renderer, w, h);

    SDL_SetRenderDrawColor(renderer, 25, 188, 25, 200);

    SDL_Rect rct;
    rct.h = 60;
    rct.w = w;
    rct.x = 0;
    rct.y = h - rct.h;
    SDL_RenderFillRect(renderer, &rct);


}

void draw_rainbow(SDL_Renderer *renderer, int w, int h) {
    SDL_Color color;
    SDL_Point center;
    center.y = h - 50;
    center.x = w / 2;

    float radius = center.x - 45;
    double x0, y0, x1, y1;
    for (float dr{0}; dr<40; dr+=0.3) {
        x0 = center.x - float (radius + dr) * cos(0);
        y0 = center.y - float (radius + dr) * sin(0);

        float wavelength = 380.0 + (750-380) * dr/40;

        color = wavelength_to_rgb( wavelength );
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 128);
        for (float th{0} ; th < M_PI; th += 0.1 ) {
            x1 = center.x - float (radius + dr) * cos(th);
            y1 = center.y - float (radius + dr) * sin(th);
            SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
            x0 = x1;
            y0 = y1;
        }
    }
}


SDL_Color
wavelength_to_rgb(float wavelength, float gamma) {
    // This function was converted from a python script found at
    // http://www.noah.org/wiki/Wavelength_to_RGB_in_Python
    // which converts a given wavelength of light to an approximate RGB color
    // value. The wavelength must be given in nanometers in the range from 380
    // nm through 750 nm (789 THz through 400 THz).
    // Based on code by Dan Bruton
    // http://www.physics.sfasu.edu/astro/color/spectra.html

    SDL_Color c;
    if (wavelength >= 380 && wavelength <= 440) {
        float attenuation = 0.3 + 0.7 * (wavelength - 380) / (440 - 380);
        c.r = pow(((-(wavelength - 440) / (440 - 380)) * attenuation), gamma);
        c.g = 0.0;
        c.b = pow((1.0 * attenuation), gamma);
    } else if(wavelength >= 440 && wavelength <= 490) {
        c.r = 0.0;
        c.g = pow(((wavelength - 440) / (490 - 440)), gamma);
        c.b = 1.0;
    } else if (wavelength >= 490 && wavelength <= 510) {
        c.r = 0.0;
        c.g = 1.0;
        c.b = pow((-(wavelength - 510) / (510 - 490)), gamma);
    } else if(wavelength >= 510 && wavelength <= 580) {
        c.r = pow(((wavelength - 510) / (580 - 510)), gamma);
        c.g = 1.0;
        c.b = 0.0;
    } else if (wavelength >= 580 && wavelength <= 645) {
        c.r = 1.0;
        c.g = pow((-(wavelength - 645) / (645 - 580)), gamma);
        c.b = 0.0;
    } else if(wavelength >= 645 && wavelength <= 750) {
        float attenuation = 0.3 + 0.7 * (750 - wavelength) / (750 - 645);
        c.r = pow((1.0 * attenuation), gamma);
        c.g = 0.0;
        c.b = 0.0;
    } else {
        c.r = 0.0;
        c.g = 0.0;
        c.b = 0.0;
    }

    c.r *= 255;
    c.g *= 255;
    c.b *= 255;

    c.a = 200;
    return c;
}

