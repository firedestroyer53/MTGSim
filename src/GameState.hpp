#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "Pile.hpp"
#include "Stack.hpp"
#include "Effect.hpp"

#include <map>

enum Phase {
    untap,
    upkeep,
    draw,
    main1,
    combat,
    combatAttacking,
    combatBlocking,
    combatDamage,
    main2,
    end
};

struct GameState {
    // this class will include everything on the board, off the board, the stack, and stuff in graveyards. It will be passed into every item every game action, and effects will happen from there.
    Phase currentPhase;
    std::map<int, Pile> decks; // TODO: Player ID 
    std::map<int, Pile> graveyards; 
    std::map<int, Pile> exiles;
    std::map<int, Pile> battlefields;
    std::map<int, Pile> commandZones;
    std::map<int, Pile> phasedOut;
    Stack stack;

    
};

#endif // GAMESTATE_HPP