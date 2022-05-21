
#ifndef __120B_PINS_H
#define __120B_PINS_H

typedef unsigned char uint8_t;

enum pin_t : uint8_t {
    BL=A0,      // brown
    BLN=A1,     // red
    WL=A2,      // orange
    PREC=A3,    // yellow
    AMP=A4,     // green
    // NC       // blue
    // VDD      // purple
    // GND      // gray
    // VDD/2    // white

    B_T_PRECHARGE=12,
    B_T_AMP=10,
    B_T_SRAM=8,
    B_F_WRITE0=5,
    B_F_WRITE1=2,
    B_F_READ=3
};

#endif
