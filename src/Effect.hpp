#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include "GameState.hpp" // Assuming GameState is defined elsewhere

struct EffectCounter; // Forward declaration

class Effect {
protected:
    std::vector<EffectCounter> counters;
    void interact(GameState& gameState);
public:
    Effect() {
        
    }
};

#endif // !EFFECT_HPP