#pragma once

#include <iostream>

#include "SDL2/SDL.h"

class Game {

    public:
        Game();
        ~Game();

        void init(const char *title, int w, int h, bool fullscreen);

        void update();
        void render();
        void clean();


    private: 
        SDL_Renderer *renderer;
        SDL_Window *window;

};