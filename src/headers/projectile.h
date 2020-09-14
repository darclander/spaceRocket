#pragma once

#include <iostream>
#include <cmath>

#include "SDL2/SDL.h"
#include "SDL2/SDL_Image.h"

class Projectile {

    public:
        Projectile(int x, int y, int d);
        ~Projectile();

        void draw(SDL_Renderer *renderer);
        void update();

    private:
        SDL_Rect p;
        int degrees;

};