#pragma once

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_Image.h"

class Projectile {

    public:
        Projectile(int x, int y);
        ~Projectile();

        void draw(SDL_Renderer *renderer);
        void update();

    private:
        SDL_Rect p;

};