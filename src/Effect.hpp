#ifndef EFFECT_HPP
#define EFFECT_HPP


struct GameState;


class Effect {
public:
    GameState interact(GameState gameState);
};

#endif // !EFFECT_HPP