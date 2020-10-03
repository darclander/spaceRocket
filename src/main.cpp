#include <iostream>
#include <vector>

#include "SDL2/SDL.h"

#include "gui.h"
#include "controller.h"
#include "rocket.h"
#include "game.h"
#include "button.h"
#include "projectile.h"

#define FPS 60
#define frameDelay = 1000 / FPS

void fpsCap(Uint32 starting_tick) {
    if ((1000 / FPS) > SDL_GetTicks() - starting_tick) {
        SDL_Delay(1000 / FPS - (SDL_GetTicks() - starting_tick));
    }
}

int main(int argc, char *argv[]) {


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        std::cout << "Cant init audio";
    }
    // Amount of channels (Max amount of sounds playing at the same time)
    Mix_AllocateChannels(32);

    // Variable initialization, all variables which will be used in the main-scope.
    
    // const int FPS = 60; // Set fps for game
    // const int frameDelay = 1000 / FPS; // ???
    
    // Will be used for SDL_GetTicks(), see https://wiki.libsdl.org/SDL_GetTicks
    uint32_t startingTick;
    int endTick;

    Game *game = new Game();
    Controller *controller = new Controller();
 


    game->init("Test", 1680, 800, false);



    while (controller->getRunning()) { // Change condition later
        startingTick = SDL_GetTicks();

        //r->draw();

// Do stuff



        controller->handleEvents();
        game->clearRenderer();
        game->update();
        game->render();
        // Cap for frames per second.
        fpsCap(startingTick);

    }

    game->clean();

    // Be sure to always delete NEW objects.

    delete game;
    delete controller;
    return 0;
}