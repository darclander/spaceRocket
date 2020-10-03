#include "pong.h"

Pong::Pong(SDL_Renderer *r, int x, int y, int w, int h) {
    renderer = r;
    this->r = g = b = a = 255;
    
    pongRect.w = w;
    pongRect.h = h;
    pongRect.x = x;
    pongRect.y = y;
}

Pong::~Pong() {

}

void Pong::draw() {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderDrawRect(renderer, &pongRect);
  SDL_RenderFillRect(renderer, &pongRect);
}

void Pong::update() {

    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    // Controls for player 1
    if(key_state[SDL_SCANCODE_W]) {
        pongRect.y -= 10;
    }
    if (key_state[SDL_SCANCODE_S]) {
        pongRect.y += 10;
    } 
    if (key_state[SDL_SCANCODE_A]) {
        pongRect.x -= 10;
    }
    if (key_state[SDL_SCANCODE_D]) {
        pongRect.x += 10;
    }

}