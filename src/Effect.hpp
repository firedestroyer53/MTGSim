#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include "GameState.hpp" // Assuming GameState is defined elsewhere

struct EffectCounter; // Forward declaration

class Effect {
protected:
    int owner; // player ID
    int id; // effect ID
    std::vector<EffectCounter> counters;
    void interact(GameState& gameState);
    
public:
    vector<cardType> types;
    Effect() {
        
    }
};

#endif // !EFFECT_HPP