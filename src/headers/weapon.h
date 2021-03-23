#pragma once

#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_Image.h"

#include "object.h"

class Weapon : public Object {

    public:
        Weapon(SDL_Renderer *r, const char *imgPath);
        ~Weapon();

};