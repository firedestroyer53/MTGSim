#include "Effect.hpp"
#include "GameState.hpp"


class Spell : public Effect {
    GameState interact(GameState gameState) {
        if (auto spellAction == dynamic_cast<Spell*>(gameState.lastGameAction)) {

        }
    }
};