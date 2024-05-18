#include "Effect.hpp"
#include "GameState.hpp"

class Spell : public Effect {
    bool onStack;
    bool isResolved;
    vector<std::map<int, Mana>> manaCost; // the map is the number of mana of each type

    void interact(GameState& gameState) {
        if (auto spellAction == dynamic_cast<Spell*>(gameState.lastGameAction)) {
            
        }
    }
    
};

class LightningBolt : public Spell {
    void interact(GameState& gameState) {
        
    }

};