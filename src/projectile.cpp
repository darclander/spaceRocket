#include "projectile.h"

Projectile::Projectile(int x, int y, int d) {
    degrees = d;
    p.x = x;
    p.y = y;
    p.w = p.h = 5;
    std::cout << "sin: " << sin(((90+degrees)*3.14)/180) << std::endl;
    std::cout << "cos: " << cos(((90+degrees)*3.14)/180) << std::endl;
}

Projectile::~Projectile() {

}

void Projectile::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &p);
    SDL_RenderFillRect(renderer, &p);
}

void Projectile::update() {
    float new_x = 3*cos(((90+degrees)*3.14)/180);
    float new_y = 3*sin(((90+degrees)*3.14)/180);
    // First quadrant
    if ( new_y > 0.1 ) {
        p.y -= new_y;
    } else if ( new_y < -0.1) {
        p.y -= new_y;
    } else {
        p.y -= 0;
    }

    if ( new_x > 0.1) {
        p.x -= new_x;
    } else if ( new_x < -0.1) {
        p.x -= new_x;
    } else {
        p.x -= 0;
    }


//          |
//     a    |   b
//          |
//  ------------------
//          |
//     c    |   d
//          |
// a should be working now.
// implement b,c,d

// a sin+ cos+
// b sin+ cos-
// c sin- cos+
// d sin- cos-

}