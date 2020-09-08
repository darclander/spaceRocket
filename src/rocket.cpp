#include "rocket.h"

Rocket::Rocket(Game game) {
    ui = game;

    SDL_Surface *tempSurface = IMG_Load("./duk.png");

    if (!tempSurface) {
        std::cout << "Failed to load picture" << IMG_GetError();
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ui.getRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);

    texture = tex;

}

Rocket::~Rocket() {
    SDL_DestroyTexture(texture);
}

void Rocket::draw() {
    SDL_Rect x;
    x.w = x.y = x.h = x.x = 100;
    SDL_RenderCopyEx(ui.getRenderer(), texture, NULL, &x, 30, NULL, SDL_FLIP_NONE);
}

