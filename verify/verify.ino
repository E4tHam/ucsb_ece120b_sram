
#include "buttons.hpp"

void setup() {
    for (auto & b : buttons) {
        b.init();
        b.update();
    }
}

void loop() {
    for (auto & b : buttons) {
        if ( !b.c && b.prev )
            b.handle();
        b.update();
    }
    delayMicroseconds(10000);
}
