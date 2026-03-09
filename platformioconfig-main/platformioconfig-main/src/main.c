#define F_CPU 8000000UL
#include <avr/io.h>
#include "avhal/DIGITALIO.h"

int main()
{
  // UCSRA Registerwert auf LEDs ausgeben
  IO_OutputRegisterToLEDs(UCSRA);

  while(1)
  {
  }
}
