#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "window.h"

    typedef struct {
        SDL_Rect draw_rect;    // dimensions of button
        struct {
            Uint8 r = 255, g = 255, b = 255, a = 255;
        } colour;

        bool pressed = 0;
        int x;
        int y;
    }button_t;

class Button : public Window {
public: 


public:
    Button(const Window &window, int x, int y);
    ~Button();

    bool drawButton();
    void button_process_event(const SDL_Event *ev);
    void create(int r, int g, int b);

private:
    button_t _button;


};