#include "controller.h"

Controller::Controller() {
    isRunning = true;
}

Controller::~Controller() {

}

void Controller::handleEvents() {
    
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT : 
            isRunning = false;
            break;
        default:
            break;
    }

}


bool Controller::getRunning() {
    return isRunning;
}