#include "rocket.h"

Rocket::Rocket(SDL_Renderer *r, std::vector<Projectile> &v) {
    vect = &v;
    renderer = r;
    degrees = 0;
    rImg.x = rImg.y = rImg.w = rImg.h = 100;

    // ROCKET SHOULDNT HANDLE ALL THE SOUNDS.

    
    shoot = new Sound("./sounds/collision.wav", 5);

    SDL_Surface *tempSurface = IMG_Load("../img/duk.png");

    if (!tempSurface) {
        std::cout << "Failed to load picture: " << IMG_GetError();
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(r, tempSurface);
	SDL_FreeSurface(tempSurface);

    texture = tex;

}

Rocket::~Rocket() {
    delete shoot;
    SDL_DestroyTexture(texture);
}


void Rocket::update() {
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    // Controls for player 1
    if(key_state[SDL_SCANCODE_W]) {
        rImg.y -= 10;
    }
    if (key_state[SDL_SCANCODE_S]) {
        rImg.y += 10;
    } 
    if (key_state[SDL_SCANCODE_A]) {
        rImg.x -= 10;
        degrees -= 10;
    }
    if (key_state[SDL_SCANCODE_D]) {
        rImg.x += 10;
        degrees += 10;
    }
    if (key_state[SDL_SCANCODE_SPACE]) {
        i++;
        if(i > 1) {
            vect->push_back(Projectile(rImg.x, rImg.y, degrees));
            shoot->play();
            i = 0;
        }
    }
}

void Rocket::draw() {
    SDL_RenderCopyEx(renderer, texture, NULL, &rImg, degrees, NULL, SDL_FLIP_NONE);
}

