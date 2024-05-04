#include "Effect.hpp"
#include <vector>

using std::vector;

struct Stack {
    vector<Effect> stack;
    Effect pop() {
        Effect effect = stack[0];
        stack.erase(stack.begin());
        return effect;
    }
    void push(Effect effect) {
        stack.insert(stack.begin(), effect);
    }
};