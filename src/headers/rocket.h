#pragma once

#include <iostream>

#include "game.h"

#include "SDL2/SDL.h"


class Rocket {

    
    public:
        Rocket(Game game);
        ~Rocket();

        void draw();


    private:
        Game ui;
        SDL_Texture *texture;


};