#pragma once

#include <iostream>

#include "SDL2/SDL.h"


class Controller {

    public:

        Controller();
        ~Controller();

        void handleEvents();
        bool getRunning();

    private: 

        bool isRunning;
        SDL_Event event;

};