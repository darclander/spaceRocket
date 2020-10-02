#include "button.h"

Button::Button(SDL_Renderer *r, int x, int y) {
    _button.draw_rect.w = 100;
    _button.draw_rect.h = 100;
    _button.draw_rect.x = x;
    _button.draw_rect.y = y;

    renderer = r;

    font = TTF_OpenFont("Roboto-Black.ttf", 14);
    if(!font) {
        fprintf(stderr, "Couldn't load font\n");
    }

}

Button::~Button() {

}

void Button::draw() {
    

SDL_Color White = {255, 255, 255};
SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "hello", White); 
SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); 

SDL_Rect Message_rect; //create a rect
Message_rect.x = 100;  //controls the rect's x coordinate 
Message_rect.y = 100; // controls the rect's y coordinte
Message_rect.w = 10; // controls the width of the rect
Message_rect.h = 10; // controls the height of the rect


SDL_RenderCopy(renderer, Message, NULL, &Message_rect); 
SDL_FreeSurface(surfaceMessage);
SDL_DestroyTexture(Message);
}

void Button::button_process_event(const SDL_Event *ev) {
    // react on mouse click within button rectangle by setting 'pressed'
    if(ev->type == SDL_MOUSEBUTTONDOWN) {
        if(ev->button.button == SDL_BUTTON_LEFT &&
                ev->button.x >= _button.draw_rect.x &&
                ev->button.x <= (_button.draw_rect.x + _button.draw_rect.w) &&
                ev->button.y >= _button.draw_rect.y &&
                ev->button.y <= (_button.draw_rect.y + _button.draw_rect.h)) {
            _button.pressed = true;
        }
    }
}
