#include "button.h"

Button::Button(const Window &window, int x, int y) : Window(window) {
    _button.draw_rect.w = 100;
    _button.draw_rect.h = 100;
    _button.draw_rect.x = x;
    _button.draw_rect.y = y;
}

void Button::create(int r, int g, int b) {
    
}

bool Button::drawButton() {
    // draw button
    SDL_SetRenderDrawColor(_renderer, _button.colour.r, _button.colour.g, _button.colour.b, _button.colour.a);
    SDL_RenderFillRect(_renderer, &_button.draw_rect);

    // if button press detected - reset it so it wouldn't trigger twice
    if(_button.pressed) {
        _button.pressed = false;
        std::cout << "YES PRESSED";
        return true;
        
    }
    return false;
}

// bool Button::drawButton(button_t *btn) {
//     // draw button
//     SDL_SetRenderDrawColor(_renderer, btn->colour.r, btn->colour.g, btn->colour.b, btn->colour.a);
//     SDL_RenderFillRect(_renderer, &btn->draw_rect);

//     // if button press detected - reset it so it wouldn't trigger twice
//     if(btn->pressed) {
//         btn->pressed = false;
//         std::cout << "YES PRESSED";
//         return true;
        
//     }
//     return false;
// }

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
