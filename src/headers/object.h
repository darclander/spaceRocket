#pragma once

#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_Image.h"



class Object {

    
    public:
        Object(SDL_Renderer *r, const char *imgPath);
        ~Object();

        void draw();
        void update();


    private:
        int degrees = 0;
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        SDL_Rect rImg;
        const char *imgPath;

};