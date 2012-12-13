/*
 * Compiled with Atmel Studio 4.18 SP3 using WinAVR-20100110.
 * Run on an Atmega8 on STK500 at 8Mhz using the board
 * LED (EXTERN_LED_OUT) and an external LED array on port D.
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define INTERN_LED_OUT		PORTB
#define EXTERN_LED_OUT		PORTD
#define POST_PRESCALE_VAL	(F_CPU / 8 / 256)

static void init_ports(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
}

static void init_timers(void)
{
	TCCR0 |= (1 << CS01); /* Prescale 8 */
	TIMSK |= (1 << TOIE0); /* Activate timer interrupt at overflow */

	sei(); /* Enable global interrupts */
}

static void led_show_number(const uint8_t n)
{
	/* convert number to BCD format */
	const uint8_t upper = n / 10;
	const uint8_t lower = n % 10;
	const uint8_t bcd_val = (upper << 4) + lower;

	INTERN_LED_OUT = ~n;
	EXTERN_LED_OUT = bcd_val;
}

/* Defined volatile because it is written inside the interrupt routine */
volatile uint16_t post_prescale = 0;

int main(void)
{
	init_ports();
	init_timers();

   uint8_t seconds = 0;
   
	for (;;)
	{
		if (post_prescale >= POST_PRESCALE_VAL)
		{
			led_show_number(seconds++);
			post_prescale = 0;
		}
	}
	return 0;
}

ISR (TIMER0_OVF_vect)
{
	post_prescale++;
}
