#include "avrhal/ugly-usart.h"
#include <avr/interrupt.h>
#include <util/delay.h>

#define LOOP_DELAY_MS 500

int main(void)
{
    usartSetup(9600);
    uint8_t message[] = "Wir Brauchen diese Serielle Schnittstelle das nächste mal auch noch.\n\r";
    sei();
    while (1) {
        _delay_ms(LOOP_DELAY_MS); 
        usartWriteString(message, strlen((char*)message));
    }



    return 0;
}
