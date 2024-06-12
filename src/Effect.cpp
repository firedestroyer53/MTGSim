#include "Effect.hpp"
#include "GameState.hpp"
#include "utility.hpp"

class Spell : public Effect {
    bool onStack;
    bool isResolved;
    vector<std::map<int, Mana>> manaCost; // the map is the number of mana of each type

    void interact(GameState& gameState) {
        // adding some default functions
        // on cast
        if (auto spellAction == dynamic_cast<Spell*>(gameState.lastGameAction) && !isResolved) {
            onCast(gameState);
        }
        // on resolve
        if (auto spellAction == dynamic_cast<Spell*)(gameState.lastGameAction) && isResolved {
            onResolve(gameState);
        }
    }
    virtual void onCast(GameState& gameState);
    virtual void onResolve(GameState& gameState);
};

class LightningBolt : public Spell {
    int targetID;
    vector<int> validTargets
    void interact(GameState& gameState) {

    }
    void onCast(GameState& gameState) {
        // get legal targets
        for (Effect e : gameState.battlefield) {
            if (vectorContains(e.types, cardType::creature) || vectorContains(e.types, cardType::planeswalker)) {
                validTargets.push_back(e.id);
            }
        }
        for (int player : gameState.playerIDs) {
            validTargets.push_back(player);
        }
        // prompt the user somehow, for now just choose first target
        targetID = validTargets[0];        

        gameState.stack.push(&this);
    }
    void onResolve(GameState& gameState) {
        if(vectorContains(validTargets, targetID)) { // check if still valid
            this->dealDamage(gameState, targetID, 3);
        }
    }
};