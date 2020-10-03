#pragma once

#include <string>
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

    typedef struct {
        SDL_Rect draw_rect;    // dimensions of button
        struct {
            Uint8 r = 255, g = 255, b = 255, a = 255;
        } colour;

        bool pressed = 0;
        int x;
        int y;
    }button_t;

class Button {

    public:
        Button(SDL_Renderer *r, int x, int y);
        ~Button();

        void draw();
        void button_process_event(const SDL_Event *ev);

    private:
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        SDL_Rect rImg;
        button_t _button;
        TTF_Font *font;

        void drawTexture(SDL_Renderer *renderer, SDL_Texture *img, int x, int y);

};