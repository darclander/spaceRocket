#pragma once

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_Image.h"


class Rocket {

    
    public:
        Rocket(SDL_Renderer *r);
        ~Rocket();

        void draw(SDL_Renderer *r);
        void update();


    private:
        SDL_Texture *texture;
        SDL_Renderer *renderer;


};