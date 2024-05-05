#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "Effect.hpp" 

struct Effect;

using std::vector;

struct Stack {
    vector<Effect*> stack;
    
    Stack() : stack() {}
    
    Stack(vector<Effect*> effects) {
        stack = effects;
    }

    Effect* pop() {
        if (!stack.empty()) {
            Effect* effect = stack.back();
            stack.pop_back();
            return effect;
        }
        return nullptr;
    }

    void push(Effect* effect) {
        stack.push_back(effect);
    }
};

#endif // !STACK_HPP
