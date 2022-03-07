#include <iostream>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include "SDL2Wrapper/SDL2.h"

void clearWindow(DZS::SDL2Renderer *r);
bool handleEvents(bool& done, int& rule);
std::vector<std::vector<bool>> initializeWolfram(size_t columns);
void draw_wolfram(DZS::SDL2Renderer* r, const std::vector<std::vector<bool>>& rows);
std::vector<bool> next_row(int rule, const std::vector<bool>& r);

int main(int argc, char *argv[], char *envp[]) {
    DZS::SDL2 sdl;
    if (sdl.isInitialized()) {
        // window setup
        auto w{sdl.createWindow()};
        auto r = w->renderer();
        bool done = false;

        std::vector<std::vector<bool>> rows;
        int rule{0};
        size_t state{0};

        TTF_Init();

        TTF_Font* font = TTF_OpenFont("/System/Library/Fonts/Supplemental/Arial Narrow.ttf", 24);




        while (!done) {
            clearWindow(r);
            // Draw your scene in the draw function
            r->set_draw_color(255,255,255,255);
            if (state==0) {
                rows = initializeWolfram(200);
                state = 1;
            }

            draw_wolfram(r, rows);

            SDL_Color color = { 255, 255, 255 };
            SDL_Surface * surface = TTF_RenderText_Solid(font,"Welcome to Gigi Labs", color);
            r->render_texture(10, 10, 200, 20, surface);

            while( rows.size() < 125 ) {
                rows.emplace_back(next_row( rule, rows.back()));
            }

            // loop cleanup
            r->present();
            if(handleEvents(done, rule)) {
                state=0;
            }
        }
    }

    // Clean up and quit SDL2
    return 0;
}

std::vector<std::vector<bool>> initializeWolfram(size_t columns) {
    std::vector<std::vector<bool>> rows;
    rows.resize(1);
    rows[0].resize(columns);

    std::generate(rows[0].begin(), rows[0].end(), [&]{
        double v = ((double)arc4random() / UINT32_MAX);
        return false; //0.5 > v;
    });

    size_t i{rows.front().size()/2};
    rows.front()[i] = true;
    return rows;
}

void draw_wolfram(DZS::SDL2Renderer* r, const std::vector<std::vector<bool>>& rows) {
    size_t row{0};
    std::for_each(rows.begin(), rows.end(), [r, &row](const auto& cells) {
        size_t col{0};
        std::for_each(cells.begin(), cells.end(), [r, &col, row](const auto& v){
            if (v) {
                r->draw_rect(col * 3 + 25, row * 3 + 25, 3, 3);
            }
            ++col;
        });
        ++row;
    });
}

bool isBitSet(int num, int bit) {
    return 1 == ( (num >> bit) & 1);
}

std::vector<bool> next_row(int rule, const std::vector<bool>& r) {
    std::vector<bool> nxt(r.size());

    for (size_t i{2} ; i < nxt.size() - 2 ; ++i) {
        nxt[i] = isBitSet(rule, 1 * r[i-2] + 2 * r[i-1] + 4 * r[i] + 8 * r[i+1] + 16 * r[i+2]);
    }
    return nxt;
}

void clearWindow(DZS::SDL2Renderer *r) {
    r->set_draw_color(0, 0, 0, 255);
    r->clear();
}

bool maybeQuit(const SDL_Event &event) {
    return  event.type == SDL_QUIT;
}

bool maybeChangeRule(const SDL_Event &event, int& rule) {
    if (event.type == SDL_KEYUP) {
        const auto k = event.key.keysym;

        if (k.scancode==SDL_SCANCODE_A) {
            rule--;
            return true;
        }

        if (k.scancode==SDL_SCANCODE_S) {
            rule++;
            return true;
        }
    }
    return false;
}

bool handleEvents(bool& done, int& rule) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        done = maybeQuit(event);
        if(maybeChangeRule(event, rule)) {
            std::cout << "[" << rule << "]" << "\n";
            return true;
        }
    }
    return false;
}
