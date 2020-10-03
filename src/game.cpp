#include "game.h"

Game::Game() {

}

Game::~Game() {
    delete rocket;
    delete b;
    delete p;
}

int Game::init(const char *title, int w, int h, bool fullscreen) {
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

        if(TTF_Init() != 0) {
            fprintf(stderr, "Couldn't init SDL_ttf: %s\n", TTF_GetError());
            return 1;
        }
        
    }
    rocket = new Rocket(renderer, vect);
    b = new Button(renderer, 10, 10);
    p = new Pong(renderer, 10, 10, 100, 200);
    return 0;
}

void Game::update() {
    for(std::vector<Projectile>::iterator it = vect.begin(); it != vect.end(); ++it) {
        it->update();
        it->draw(renderer);
    }

    rocket->draw();
    rocket->update();

    b->draw();

    p->draw();
    p->update();

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


