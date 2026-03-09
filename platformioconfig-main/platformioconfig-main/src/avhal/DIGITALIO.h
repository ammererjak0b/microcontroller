#include <avr/io.h>
void IO_SetAllPORTAToOutput();
void IO_SetAllPORTAToHigh();
void IO_SetAllPORTAToLow();
void IO_OutputRegisterToLEDs(uint8_t value);