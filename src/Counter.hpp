#ifndef COUNTER_HPP
#define COUNTER_HPP

struct Effect; // Forward declaration

struct EffectCounter {
    Effect *attachedTo;
    int number;
    // TODO: Counter types.
};

struct PlayerCounter {
    int attachedTo; // player ID that the counter is attached to
    int number;
};

#endif // !COUNTER_HPP