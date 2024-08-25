#include "ioCC2530.h"

#define LED1 P1_0

typedef unsigned int uint8;

void initIO() {
    P1DIR |= 0x01;
    P1SEL &= ~0x01; 
}

void delayMs(uint8 ms) {
    uint8 i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 538; j++);
}

int main() {
    initIO();
    while (1) {
        LED1 = 0;
        delayMs(500);
        LED1 = 1;
        delayMs(500);
    }
}
