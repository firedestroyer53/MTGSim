#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "Pile.hpp"
#include "Stack.hpp"
#include "Effect.hpp"
#include "Counter.hpp"

#include <map>

enum Phase {
    untapStep,
    upkeepStep,
    drawStep,
    main1,
    combatStep,
    combatAttacking,
    combatBlocking,
    combatDamage,
    main2,
    endStep
};

enum Mana {
    white,
    blue,
    black,
    red,
    green,
    colorless
};

struct GameState {
    // this class will include everything on the board, off the board, the stack, and stuff in graveyards. It will be passed into every item every game action, and effects will happen from there.
    Phase currentPhase;
    vector<int> playerIDs;
    std::map<int, Pile> decks; // TODO: Player ID 
    std::map<int, Pile> graveyards; 
    std::map<int, Pile> exiles;
    std::map<int, Pile> battlefields;
    std::map<int, Pile> commandZones;
    std::map<int, Pile> phasedOut;
    std::map<int, Pile> hands;
    std::map<int, int> lifeTotals;
    std::map<int, std::map<int , Mana>> manaPools; // TODO: change the int to conditions for the mana
    std::map<int, int> playerHandSizes;
    std::map<int, PlayerCounter> counters;
    
    int priority; // will be the player ID that has priority

    int playerTurn;

    Stack stack;

    Effect lastGameAction;
};

#endif // GAMESTATE_HPP