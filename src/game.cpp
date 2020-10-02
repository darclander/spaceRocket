#include "game.h"

Game::Game() {

}

Game::~Game() {
    delete rocket;
}

void Game::init(const char *title, int w, int h, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(
                                    title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    w,
                                    h,
                                    flags
        );
        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

    }
    rocket = new Rocket(renderer, vect);
}

void Game::update() {
    for(std::vector<Projectile>::iterator it = vect.begin(); it != vect.end(); ++it) {
        it->update();
        it->draw(renderer);
    }

    rocket->draw(renderer);
    rocket->update();
}

void Game::render() {
    SDL_RenderPresent(renderer);
}

void Game::clearRenderer() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}


void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


