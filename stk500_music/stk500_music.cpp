/*
 * Compiled with Atmel Studio 4.18 SP3 using WinAVR-20100110.
 * Run on an Atmega32 on STK500 at 8Mhz with a speaker
 * connected at port D.
 */

#include "Note.hpp"
#include "Song.hpp"
#include "MusicPlayer.hpp"

#include "btn5.hpp"
#include "btn6.hpp"
#include "btn7.hpp"

#include <avr/io.h>
#include <avr/interrupt.h>

namespace {

// Communication with the overflow interrupt.
volatile uint16_t hertz_prescale = 0;
volatile uint16_t note_prescale = 0;

void init_ports()
{
   // The speaker will be connected to port D.
	DDRD = 0xff;
}

void init_timers()
{
	TCCR0 = (0 << CS02) | (0 << CS01) | (1 << CS00); // Prescale 1
	TIMSK |= (1 << TOIE0); // Activate timer interrupt at overflow

	sei(); // Enable global interrupts.
}

// Returns the id of the pressed button or -1 if not button is pressed.
int8_t get_pressed_btn()
{
   const uint8_t pin = PINA;
   if (!(pin & (1 << PA0))) return 0;
   else if (!(pin & (1 << PA1))) return 1;
   else if (!(pin & (1 << PA2))) return 2;
   else if (!(pin & (1 << PA3))) return 3;
   else if (!(pin & (1 << PA4))) return 4;
   else if (!(pin & (1 << PA5))) return 5;
   else if (!(pin & (1 << PA6))) return 6;
   else if (!(pin & (1 << PA7))) return 7;
   else return -1;
}

} // unnamed-namespace

int main()
{
   init_ports();
   init_timers();
   
   MusicPlayer player;
   player.SetSong(5, &btn5_song); // Imperial March (horribly wrong)
   player.SetSong(6, &btn6_song); // Gummibaerenbande Intro
   player.SetSong(7, &btn7_song); // Oh du froehliche

   while (true)
   {
      const uint8_t btn = get_pressed_btn();
      if (-1 != btn)
      {
         player.SwitchTo(btn);
         
         PORTD = 0;
         hertz_prescale = 0;
         note_prescale = 0;
      }
      player.PlayMusic(hertz_prescale, note_prescale, PORTD);
   }
}

ISR (TIMER0_OVF_vect)
{
   hertz_prescale++;
   note_prescale++;
}
