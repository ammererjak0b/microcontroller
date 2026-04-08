#include "avrhal/ugly-usart.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

#define LOOP_DELAY_MS 500

int main(void)
{
    usartSetup(9600);
    uint8_t laborUebung = 3;
    uint8_t message[255];

    char * cow_string = 
    "  ^__^\n\r"
    "  (oo)\\_______\n\r"
    "  (__)\\       )\\/\\\n\r"
    "      ||----w |\n\r"
    "      ||     ||\n\r";

    snprintf(message, 255, "%s", cow_string);

    sei();
    while (1) {
        _delay_ms(LOOP_DELAY_MS); 
        usartWriteString(message, strlen((char*)message));
    }



    return 0;
}
