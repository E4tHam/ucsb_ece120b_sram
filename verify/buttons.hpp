
#ifndef __120B_BUTTONS_H
#define __120B_BUTTONS_H

#include "pins.h"
#include "tests.hpp"

struct button_t {
    const pin_t p;
    void (*handle)(void);
    uint8_t c, prev;
    void update(void) {prev = c; c = digitalRead(p);}
    void init(void) const {pinMode(p, INPUT_PULLUP);}
};

button_t buttons[6] = {
    {pin_t::B_T_PRECHARGE, test::precharge},
    {pin_t::B_T_AMP, test::sense_amp},
    {pin_t::B_T_SRAM, test::sram},

    {pin_t::B_F_WRITE0, full::write_0},
    {pin_t::B_F_WRITE1, full::write_1},
    {pin_t::B_F_READ, full::read}
};

#endif
