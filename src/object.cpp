#include "object.h"

Object::Object(SDL_Renderer *r, const char *imgPath) {
    this->imgPath = imgPath;
    renderer = r;
    rImg.x = rImg.y = rImg.w = rImg.h = 100;

    SDL_Surface *tempSurface = IMG_Load(imgPath);

    if (!tempSurface) {
        std::cout << "Failed to load picture: " << IMG_GetError();
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(r, tempSurface);
	SDL_FreeSurface(tempSurface);

    texture = tex;

}

Object::~Object() {

}

void Object::draw() {
    SDL_RenderCopyEx(renderer, texture, NULL, &rImg, degrees, NULL, SDL_FLIP_NONE);
}