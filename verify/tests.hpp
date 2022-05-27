
#ifndef __120B_TESTS_H
#define __120B_TESTS_H

#include "pins.h"

#define TESTS_DELAY delay(1)

// Test devices
namespace test {


// for each of the three inputs to the precharge, set high
void precharge(void) {
    // set up precharge pin
    pinMode(pin_t::PREC, OUTPUT);

    pin_t terminals[3] = {pin_t::BL, pin_t::BLN, pin_t::WL};
    for (auto p : terminals) {
        // set up terminal pin
        pinMode(p, OUTPUT);

        // disable precharge, write high
        digitalWrite(pin_t::PREC, 0);
        digitalWrite(p, 1);
        TESTS_DELAY;

        // enable precharge
        digitalWrite(pin_t::PREC, 1);
        TESTS_DELAY;

        // reset
        digitalWrite(p, 0);
    }
}


// test with both values of bl
void sense_amp(void) {
    // set up all pins
    pinMode(pin_t::BL, OUTPUT);
    pinMode(pin_t::BLN, OUTPUT);
    pinMode(pin_t::AMP, OUTPUT);

    for (uint8_t bl = 0; bl < 2; bl++) {
        // disable amp
        digitalWrite(pin_t::AMP, 0);
        // charge bl and bln
        digitalWrite(pin_t::BL, bl);
        digitalWrite(pin_t::BLN, !bl);
        TESTS_DELAY;

        // enable amp
        digitalWrite(pin_t::AMP, 1);
        TESTS_DELAY;

        // disable amp
        digitalWrite(pin_t::AMP, 0);
    }

}


// write 0, read 0, write 1, read 1
void sram(void) {
    pinMode(pin_t::BL, OUTPUT);
    pinMode(pin_t::BLN, OUTPUT);
    pinMode(pin_t::WL, OUTPUT);
    for (uint8_t bl = 0; bl < 2; bl++) {
        // charge bl and bln
        digitalWrite(pin_t::WL, 0);
        digitalWrite(pin_t::BL, bl);
        digitalWrite(pin_t::BLN, !bl);
        TESTS_DELAY;

        // write
        digitalWrite(pin_t::WL, 1);
        TESTS_DELAY;

        // read
        digitalWrite(pin_t::WL, 0);
        pinMode(pin_t::BL, INPUT);
        pinMode(pin_t::BLN, INPUT);
        digitalWrite(pin_t::WL, 1);

        // reset
        digitalWrite(pin_t::WL, 0);
    }
}


};




// Full device
namespace full {


void write(const uint8_t v) {
    // setup
    pinMode(pin_t::BL, OUTPUT);
    pinMode(pin_t::BLN, OUTPUT);
    pinMode(pin_t::WL, OUTPUT);
    pinMode(pin_t::PREC, OUTPUT);
    pinMode(pin_t::AMP, OUTPUT);
    digitalWrite(pin_t::WL, 0);
    digitalWrite(pin_t::PREC, 0);
    digitalWrite(pin_t::AMP, 0);
    TESTS_DELAY;

    // charge bl and bln
    digitalWrite(pin_t::BL, v);
    digitalWrite(pin_t::BLN, !v);
    TESTS_DELAY;

    // write
    digitalWrite(pin_t::WL, 1);
    TESTS_DELAY;

    // reset
    digitalWrite(pin_t::WL, 0);
    TESTS_DELAY;
}

void write_0(void) {write(0);}
void write_1(void) {write(1);}


void read(void) {
    // setup
    pinMode(pin_t::BL, INPUT);
    pinMode(pin_t::BLN, INPUT);
    pinMode(pin_t::WL, OUTPUT);
    pinMode(pin_t::PREC, OUTPUT);
    pinMode(pin_t::AMP, OUTPUT);
    digitalWrite(pin_t::WL, 0);
    digitalWrite(pin_t::PREC, 0);
    digitalWrite(pin_t::AMP, 0);

    // precharge and enable amp
    digitalWrite(pin_t::PREC, 1);
    digitalWrite(pin_t::AMP, 1);
    TESTS_DELAY;

    // read to out
    digitalWrite(pin_t::WL, 1);
    TESTS_DELAY;

    // reset
    digitalWrite(pin_t::WL, 0);
    digitalWrite(pin_t::PREC, 0);
    digitalWrite(pin_t::AMP, 0);
}

};


#endif
