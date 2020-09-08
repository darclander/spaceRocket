#include <iostream>

#include "SDL2/SDL.h"

#include "gui.h"
#include "controller.h"
#include "rocket.h"
#include "game.h"



// Game *game = nullptr; // Will be used when Game has a constructor

int main(int argc, char *argv[]) {

    Game *game = nullptr;
    Controller *controller = nullptr;

    const int FPS = 60; // Set fps for game
    const int frameDelay = 1000 / FPS;

    uint32_t startingTick;
    int endTick;
    int i = 0;

    game = new Game();
    controller = new Controller();



    game->init("Test", 800, 800, false);
    

    Rocket *r = new Rocket(*game);

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
    delete game;
    delete r;
    delete controller;
    return 0;
}