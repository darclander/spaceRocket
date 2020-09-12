#pragma once

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "rocket.h"

class Game {

    public:
        Game();
        ~Game();

        void init(const char *title, int w, int h, bool fullscreen);

        void update();
        void render();
        void clearRenderer();
        void clean();

    private: 
        SDL_Renderer *renderer;
        SDL_Window *window;

        SDL_Event event;
        std::vector<Projectile> vect; // to add projectiles
        Rocket *rocket;

};