#define SDL_MAIN_HANDLED

#include "main.hpp"
#include "Pile.hpp"
#include "Card.hpp"
#include "SDLHelpers.hpp"
#include "GameState.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = SCREEN_WIDTH * 1.4;  

int main(int argc, char *argv[]) {
    
    if (!initializeSDL(SCREEN_WIDTH, SCREEN_HEIGHT)) {
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    initialize();
    loadContent();

    while (!quit) {
        while (SDL_PollEvent( & e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        update();
        draw();
    }
    closeSDL();
}


void initialize() {
    string fileName = "decklist.txt";
}

void loadContent() {
    
}

int counter = 0;
void update() {
    LightningBolt bolt;
    
}

void draw() {
    SDL_SetRenderDrawColor(renderer, 1, 5, 136, 255);
    SDL_RenderClear(renderer);
    

    SDL_RenderPresent(renderer);
}