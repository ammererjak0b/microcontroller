#include <avr/io.h>

void IO_SetAllPORTAToOutput() {
    DDRA = 0xFF;
}

void IO_SetAllPORTAToHigh() {
    PORTA = 0xFF;
}

void IO_SetAllPORTAToLow() {
    PORTA = 0x00;
}