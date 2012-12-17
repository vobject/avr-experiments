/*
 * Compiled with Atmel Studio 4.18 SP3 using WinAVR-20100110.
 * Run on an Atmega32 on STK500 at 8Mhz with a speaker
 * connected at PORTD.
 */

#include "uart.h"

#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>

static void ports_init(void)
{
	DDRD = 0xff; /* Speaker will be connected to PORTD. */
   PORTD = 0x00; /* Make sure it is off by default. */
}

static void speaker_on(void)
{
   PORTD = 0xff;
}

static void speaker_off(void)
{
   PORTD = 0x00;
}

/* The client application delivers one of 256 frequency ids via UART.
 * Each of which has to be translated to an actual delay time. */
static uint16_t delay_from_id(const uint8_t id)
{
   /* Return the time to wait until we toggle the speaker. This
    * determines the frequency in which the tone is played. */

   /* TODO */
   return 10;
}

int main(void)
{
   ports_init();
   uart_init();

   for (;;)
   {
      if (!uart_has_input()) {
         continue; /* We will only play a tone if we are asked to. */
      }
    
      /* FIXME: The frequency can never be higher than BAUD/8,
       * which might be a problem if we need high frequencies. */

      speaker_on();
      _delay_ms(delay_from_id(uart_read()));
      speaker_off();
   }
}
