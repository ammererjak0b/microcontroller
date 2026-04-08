/**
* @Authors: Mic Lab Team
*/

#ifndef usart_h_zidaSSgah23o7ier
#define usart_h_zidaSSgah23o7ier

#include <stdbool.h>
#include <stdint.h>

/** Setup and enable the usart interface
 * @param[in] baud The desired baudrate
 * @param[in] config The interface configuration (example: 8 data bits, no parity, 1 stop bit)
*/
void usartSetup(uint16_t baud);

/** Write a byte to the usart interface.
 * @param[in] byte The data byte to be transmitted
 * @return TRUE if the byte was written to the transmit buffer, false otherwise
*/
bool usartWrite(uint8_t byte);

void usartWriteString(uint8_t* character, int len);

#endif
