#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "Pile.hpp"
#include "Stack.hpp"
#include "Effect.hpp"
#include "Counter.hpp"

#include <map>

struct Effect;
struct Pile;
struct Counter;
struct Stack;


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

enum cardType {
    creature
};

struct GameState {
    Phase currentPhase;
    vector<int> playerIDs;
    std::map<int, Pile> decks;
    std::map<int, Pile> graveyards;
    std::map<int, Pile> exiles;
    vector<Effect> battlefield;
    vector<Effect> commandZones;
    vector<Effect> phasedOut;
    std::map<int, Pile> hands;
    std::map<int, int> lifeTotals;
    std::map<int, std::map<int, Mana>> manaPools;
    std::map<int, int> playerHandSizes;
    std::map<int, vector<PlayerCounter>> counters;
    int priority;
    int playerTurn;
    Stack stack;
    Effect* lastGameAction;

    GameState() {
        
    }
};

#endif // GAMESTATE_HPP