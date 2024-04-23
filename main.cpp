#define SDL_MAIN_HANDLED

#include "main.hpp"
#include "Pile.hpp"
#include "Card.hpp"
#include "SDLHelpers.hpp"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = SCREEN_WIDTH * 1.4;  

Pile deck;
Pile play;
Pile graveyard;
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
    deck = Pile(fileName);
    deck.shuffle();
    play = Pile();
    graveyard = Pile();
}

void loadContent() {
    
}

int counter = 0;
void update() {
    if (counter % 10000 == 0) {
        if (play.cards.size() == 1) {
            play.drawTo(graveyard);
        }
        deck.drawTo(play);
    }
    if (deck.cards.size() == 0) {
        while (graveyard.cards.size() > 0) {
            graveyard.drawTo(deck);
        }
    }
    counter++;
}
SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
void draw() {
    SDL_SetRenderDrawColor(renderer, 1, 5, 136, 255);
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, play.cards[0].cardTexture, NULL, &rect);

    SDL_RenderPresent(renderer);
    counter++;
}

