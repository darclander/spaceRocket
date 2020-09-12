#include "projectile.h"

Projectile::Projectile(int x, int y) {
    p.x = x;
    p.y = y;
    p.w = p.h = 5;
}

Projectile::~Projectile() {

}

void Projectile::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &p);
    SDL_RenderFillRect(renderer, &p);
}

void Projectile::update() {
    p.y -= 10;
}