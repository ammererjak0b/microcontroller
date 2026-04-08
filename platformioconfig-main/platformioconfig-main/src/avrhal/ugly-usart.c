/**
* @Authors: Mic Lab Team
*/

#include "avrhal/ugly-usart.h"
#include "utils/bit.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <util/atomic.h>
#include <util/delay.h>

uint8_t index; 
uint8_t buffer[255];

static inline void enableTransmitBufferEmptyInterrupt() 
{
	//set UDRIE 1= enable data Register empty interrupt
	BIT_SET(UCSRB, UDRIE);
}

static inline void disableTransmitBufferEmptyInterrupt() 
{
	//set UDRIE 0= disable data Register empty interrupt
	BIT_CLR(UCSRB, UDRIE);
}

void usartSetup(uint16_t baud)
{	
	//calculation of baud rate register value according to formula. 147
	uint16_t ubrrValue = (F_CPU / (16UL * baud)) - 1;

	UBRRL = (uint8_t)ubrrValue; //set baudrate to 9600 according to table on p.167
	
	// 0x86 in Binary 10000110 Asynchroner Modus; Keine Parität (None); 8 Datenbits;  1 Stoppbit
	UCSRC = 0x86; 

	UCSRB |= 1 << TXEN;
	enableTransmitBufferEmptyInterrupt(); //enable interrupt for recieving data
}

//Definiert ISR... können auch mehrere ISRS haben.
ISR(USART_UDRE_vect){
	uint8_t nextChar = buffer[index];
	if(nextChar == '\0'){
		disableTransmitBufferEmptyInterrupt();
	}
	else{
		UDR = nextChar;
		index ++;
	}
}

bool usartWrite(uint8_t byte)
{
	/* Put data into buffer, sends the data */
	UDR = byte;

	enableTransmitBufferEmptyInterrupt();
	return true;
}

void usartWriteString(uint8_t* character, int len)
{
	index = 0;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		for (index = 0; index < len; index++)
		{
			buffer[index] = character[index];		
		}
	}
	index = 0;
	enableTransmitBufferEmptyInterrupt();
	
}


