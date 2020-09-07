#include <iostream>

#include "SDL2/SDL.h"

#include "gui.h"
#include "controller.h"
#include "rocket.h"
#include "game.h"



// Game *game = nullptr; // Will be used when Game has a constructor

int main(int argc, char *argv[]) {

    Game *game = nullptr;

    const int FPS = 60; // Set fps for game
    const int frameDelay = 1000 / FPS;

    uint32_t startingTick;
    int endTick;
    int i = 0;

    game = new Game();

    game->init("Test", 800, 800, false);

    while (i++ < 10) { // Change condition later

        startingTick = SDL_GetTicks();

        // Do stuff
        game->render();

        endTick = SDL_GetTicks() - startingTick;

        if (frameDelay > endTick) {
            SDL_Delay(frameDelay - endTick);
        }

    }

    game->clean();
    return 0;
}