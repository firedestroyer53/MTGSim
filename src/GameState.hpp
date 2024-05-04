#include "Pile.hpp"
#include "Stack.hpp"


struct GameState {
    // this class will include everything on the board, off the board, the stack, and stuff in graveyards. It will be passed into every item every game action, and effects will happen from there.
    Stack stack;
};