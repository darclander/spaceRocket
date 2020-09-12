#pragma once

#include <iostream>
#include <bits/stdc++.h> 

#include "SDL2/SDL.h"
#include "SDL2/SDL_Image.h"

#include "projectile.h"

class Rocket {

    
    public:
        Rocket(SDL_Renderer *r, std::vector<Projectile> &v);
        ~Rocket();

        void draw(SDL_Renderer *r);
        void update();


    private:
        int degrees;
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        SDL_Rect rImg;
        std::vector<Projectile> *vect;
        int i;

};