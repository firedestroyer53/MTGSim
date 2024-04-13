#ifndef PILE_HPP
#define PILE_HPP

#include "Card.hpp"

#include <vector>
using std::vector;

struct Pile {
    vector<Card> uniqueCards;
    vector<Card> cards; 

    void drawTo(Pile& destinationPile);

    Pile();

    Pile(string fileName);

    void shuffle();
};
#endif // PILE_HPP