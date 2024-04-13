#include "Card.hpp"
#include "utility.hpp"

Card::Card() {}
Card::Card(string name) {
    displayName = name;
    cardName = removeSpaces(name);
}
Card::Card(string name, SDL_Texture *texture){
    cardTexture = texture;
    displayName = name;
    cardName = removeSpaces(name);
}
