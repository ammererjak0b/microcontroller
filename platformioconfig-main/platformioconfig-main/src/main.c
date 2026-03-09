#define F_CPU 8000000UL
#define LED_ON_TIME_MS 200
#define LED_OFF_TIME_MS LED_ON_TIME_MS
#include <avr/io.h>
#include <util/delay.h>
#include <avhal/DIGITALIO.h>
#include "main.h"

int main()
{
  // Alle Pins PortA auf Output setzen
  IO_SetAllPORTAToOutput();

  // nur 6tes bit auf Output setzen
  // DDRA |= (1 << DDA6);


  // DDRA |= (1 << 6);

  for (int i = 0; i < 8; i++)
  {
    PORTA |= (1 << i);
    _delay_ms(LED_ON_TIME_MS);    
    DDRA |= (0 << i);
  }
  

  while(1)
  {
    //Bitwise toggling
    //PORTA ^= 0xFF;

    // PORTA = 0xFF; 
    // _delay_ms(LED_ON_TIME_MS);
    // PORTA = 0x00;
    // _delay_ms(LED_OFF_TIME_MS);
  }
}
