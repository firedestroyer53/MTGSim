#ifndef COUNTER_HPP
#define COUNTER_HPP

struct Effect;

struct EffectCounter {
    Effect *attachedTo;
    int number;
    // TODO: Counter types.
};

struct PlayerCounter {
    int attachedTo; // player ID that the counter is attached to
    int number;

    PlayerCounter(int id) {
        attachedTo = id;
        number = 0;
    }
};

#endif // !COUNTER_HPP