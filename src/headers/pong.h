#pragma once

#include <iostream>
#include "SDL2/SDL.h"

class Pong {

    public:
        Pong(SDL_Renderer *r, int x, int y, int w, int h);
        ~Pong();

        void draw();
        void update();


    private:
        SDL_Renderer *renderer; // Passed renderer
        int r,g,b,a; // Colors

        SDL_Rect pongRect; // Has w, h, x, y

};