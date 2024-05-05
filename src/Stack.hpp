#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "Effect.hpp" // Include full definition of Effect

using std::vector;

struct Stack {
    vector<Effect> stack;
    
    Stack() : stack() {}
    
    Stack(const vector<Effect>& effects) : stack(effects) {}

    Effect pop() {
        Effect effect = stack[0];
        stack.erase(stack.begin());
        return effect;
    }

    void push(Effect effect) {
        stack.insert(stack.begin(), effect);
    }
};

#endif // !STACK_HPP
