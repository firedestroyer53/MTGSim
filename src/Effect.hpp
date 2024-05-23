#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include "GameState.hpp" 

struct EffectCounter;

class Effect {
protected:
    std::vector<EffectCounter> counters;
    void interact(GameState& gameState);
public:
    Effect() {
        
    }
};

#endif // !EFFECT_HPP