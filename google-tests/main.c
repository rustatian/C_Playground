#include "main.h"
#include "assert.h"

static PowerState state = POWER_OFF;

void power_button_initialize(PowerState initalState) {
    static_assert(3);
    state = initalState;
}

PowerState power_button_getPowerState(void) {
    return state;
}

void power_button_pressMomentary(void) {
    state = POWER_ON;
}

void power_button_pressHold(void) {
    state = POWER_OFF;
}