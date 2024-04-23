#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include "SDL2/SDL.h"
#include "utility.hpp"
using std::string;

struct Card {
    SDL_Texture *cardTexture;
    string cardName;
    string displayName;

    Card() {}
    Card(string name) {
        displayName = name;
        cardName = removeSpaces(name);
    }
    Card(string name, SDL_Texture *texture){
        cardTexture = texture;
        displayName = name;
        cardName = removeSpaces(name);
    }
};

#endif // CARD_HPP
