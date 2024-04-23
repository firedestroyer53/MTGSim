#ifndef PILE_HPP
#define PILE_HPP

#include "Card.hpp"
#include "SDLHelpers.hpp"

#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;

struct Pile {
    vector<Card> uniqueCards;
    vector<Card> cards; 

    void drawTo(Pile& destinationPile) {
        destinationPile.cards.insert(destinationPile.cards.begin(), this->cards[0]);
        this->cards.erase(this->cards.begin());
    }

    Pile() {}

    Pile (string fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        vector<string> lines;

        string line;
        while(std::getline(file, line)){
            lines.push_back(line);
        }
        file.close();

        // parse. 1 {card name} will just turn into {card name}, and 2 {card name} will turn into two instances of {card name}
        for(string cardName : lines) {
            int numCards = cardName[0] - '0';
            // remove the number
            cardName.erase(0, 2);
            // add texture
            Card card = {cardName};
            card.cardTexture = loadTexture("bmp_images/" + card.cardName + ".bmp");
            for(int i = 0; i < numCards; i++) {
                this->cards.push_back(card);
            }
        }
    }


    void shuffle() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(cards.begin(), cards.end(), gen);
    }
};
#endif // PILE_HPP