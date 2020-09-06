#include <iostream>

#include "SDL2/SDL.h"

#include "gui.h"
#include "controller.h"
#include "rocket.h"
#include "game.h"


// Game *game = nullptr; // Will be used when Game has a constructor

int main(int argc, char *argv[]) {

    std::cout << "Hello there";

    const int FPS = 60; // Set fps for game
    const int frameDelay = 1000 / FPS;

    uint32_t startingTick;
    int endTick;

    while (true) { // Change condition later

        startingTick = SDL_GetTicks();

        // Do stuff

        endTick = SDL_GetTicks() - startingTick;

        if (frameDelay > endTick) {
            SDL_Delay(frameDelay - endTick);
        }

    }


    return 0;
}