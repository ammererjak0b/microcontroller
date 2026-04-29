#include "avrhal/adc.h"
#include <avr/io.h>                                                              
#include <util/atomic.h>   
#include <utils/bit.h>   

#define X_CHANNEL 0
#define Y_CHANNEL 1

void adcSetup()
{
    ADMUX = (1 << REFS0); // set reference voltage s.214
    ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2); // set enable with ADEN, ADPS1 and 2 set prescaler to 64
}

uint16_t adcRead()
{
    ADCSRA |= (1 << ADSC); // | this to overwrite this was our bug. go deep into your memory jakob
    while(BIT_IS_SET(ADCSRA, ADSC))
    ; // do nothing
    // Single conversion here... 
    return ADCW;    
}

void adcSetChannel(__attribute__((unused)) uint8_t channel)
{
    if(channel > 8){    // Guard against greater 8 
        return; 
    }
    ADMUX &= 0xF8;      // clear the lower three bits 
    ADMUX += channel;   // (to be able to pass decimal numbers.) S.215 Datasheet
}   
 uint16_t yResult;
 uint16_t xResult;
 uint8_t currentChannel;
void adcSetupFreeRunning()
{
    SFIOR &= ~(
          (1 << ADTS2) 
        | (1 << ADTS1) 
        | (1 << ADTS0)
    );   // negate every shift. &= to only set last three bits 0. Set Free running mode
    currentChannel =X_CHANNEL;
}

int16_t adcLastRead(__attribute__((unused)) uint8_t channel)
{
    return -1;
}

ISR(ADC_vect){
    if (currentChannel == X_CHANNEL)
    {
    currentChannel = Y_CHANNEL;

    } 
    if (currentChannel == Y_CHANNEL) currentChannel = X_CHANNEL;
    // switch Channel

    adcSetChannel(currentChannel);
    if (currentChannel == Y_CHANNEL){
        xResult = ADCW;
    }
}