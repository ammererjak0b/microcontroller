#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
  DDRA = 0xFF;

  while(1)
  {
    PORTA ^= 0xFF;
    _delay_ms(200);
  }
}