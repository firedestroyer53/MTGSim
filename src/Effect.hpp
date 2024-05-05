#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include "GameState.hpp" // Assuming GameState is defined elsewhere

struct EffectCounter; // Forward declaration

class Effect {
public:
    std::vector<EffectCounter> counters;
    GameState interact(GameState gameState);
};

#endif // !EFFECT_HPP