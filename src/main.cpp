#include <iostream>

#include "SDL2/SDL.h"

#include "gui.h"
#include "controller.h"
#include "rocket.h"
#include "game.h"


int main(int argc, char *argv[]) {

    // Variable initialization, all variables which will be used in the main-scope.
    
    const int FPS = 60; // Set fps for game
    const int frameDelay = 1000 / FPS; // ???
    
    // Will be used for SDL_GetTicks(), see https://wiki.libsdl.org/SDL_GetTicks
    uint32_t startingTick;
    int endTick;

    Game *game = new Game();
    Controller *controller = new Controller();
 

    game->init("Test", 800, 800, false);
    Rocket *r = new Rocket(*game); // Has to be created after Game since its depending on where to be drawn. (Avoid public renderer in game)



    while (controller->getRunning()) { // Change condition later
        startingTick = SDL_GetTicks();

        r->draw();

        // Do stuff



        controller->handleEvents();
        game->render();

        // Cap for frames per second.
        endTick = SDL_GetTicks() - startingTick;

        if (frameDelay > endTick) {
            SDL_Delay(frameDelay - endTick);
        }

    }

    game->clean();

    // Be sure to always delete NEW objects.

    delete game;
    delete r;
    delete controller;
    return 0;
}