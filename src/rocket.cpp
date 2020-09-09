#include "rocket.h"

Rocket::Rocket(SDL_Renderer *r) {

    SDL_Surface *tempSurface = IMG_Load("./duk.png");

    if (!tempSurface) {
        std::cout << "Failed to load picture" << IMG_GetError();
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(r, tempSurface);
	SDL_FreeSurface(tempSurface);

    texture = tex;

}

Rocket::~Rocket() {
    SDL_DestroyTexture(texture);
}


void Rocket::update() {
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    // Controls for player 1
    if(key_state[SDL_SCANCODE_W]) {
        std::cout << "YES";
    }
}

void Rocket::draw(SDL_Renderer *r) {
    SDL_Rect x;
    x.w = x.y = x.h = x.x = 100;
    SDL_RenderCopyEx(r, texture, NULL, &x, 30, NULL, SDL_FLIP_NONE);
}

