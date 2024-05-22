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
    void interact(GameState& gameState) {

    }
    void onCast(GameState& gameState) {
        // get legal targets
        vector<int> targets;
        for (Effect e : gameState.battlefield) {
            if (vectorContains(e.types, cardType::creature)) {
                targets.push_back(e.id);
            }
        }
        for (int player : gameState.playerIDs) {
            targets.push_back(player);
        }
        // prompt the user somehow, for now just choose first target
        targetID = targets[0];
        // add the spell to the stack
        gameState.stack.push(this);
    }
    void onResolve() {
        
    }
};