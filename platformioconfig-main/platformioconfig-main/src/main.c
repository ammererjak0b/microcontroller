#include "avrhal/adc.h"
#include "avrhal/usart.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#define BUFFER_SIZE 255
#define LOOP_DELAY_MS 100

int main(void)
{
    usartSetup(USART_B9600, USART_CONFIG_8N1);
    adcSetup();
    adcSetupFreeRunning();

    char message[BUFFER_SIZE];

    const char *cow_string =
        "  ^__^\r\n"
        "  (oo)\\_______\r\n"
        "  (__)\\       )\\/\\\r\n"
        "      ||----w |\r\n"
        "      ||     ||\r\n";

    usartWriteString(cow_string);

    sei();    
    while (1) {

        adcSetChannel(0);
        uint16_t adcX = adcRead();

        adcSetChannel(1);
        uint16_t adcY = adcRead();

        snprintf(message, BUFFER_SIZE, "ADC x:%4d y:%4d\r\n", adcX, adcY);
        usartWriteString(message);
        _delay_ms(LOOP_DELAY_MS);
    }
}
