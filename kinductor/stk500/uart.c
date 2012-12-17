#include "uart.h"

#include <avr/io.h>

inline void uart_init(void)
{
   /* TXEN for sending, RXEN for receiving */
   UCSRB |= ( 1<< TXEN) | (1 << RXEN);

   /* 8 Bit, 1 Stopbits, no Parity */
   UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

   UBRRH = UBRR_VAL >> 8;
   UBRRL = UBRR_VAL & 0xff;
}

inline bool uart_has_input(void)
{
   return (UCSRA & (1 << RXC));
}

inline uint8_t uart_read(void)
{
   return UDR;
}
