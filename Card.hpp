#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include "SDL2/SDL.h"
using std::string;

struct Card {
    SDL_Texture *cardTexture;
    string cardName;
    string displayName;

    Card();
    Card(string name);
    Card(string name, SDL_Texture *texture);
};

#endif // CARD_HPP
