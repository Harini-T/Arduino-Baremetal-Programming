#include <avr/io.h>                    
#include <util/delay.h>

int main(void) {
  // -------- Inits --------- //
  DDRB |= 0b00100000;            /* Data Direction Register B:
                                   writing a one to DDRB5 [Digital Pin13]
                                   enables output. */

  // ------ Event loop ------ //
  while (1) {

    PORTB = 0b00100000;          /* Turn on PB5 LED bit/pin in PORTB */
    _delay_ms(500);                                           /* wait */

    PORTB = 0b00000000;          /* Turn off all B pins, including LED */
    _delay_ms(500);                                           /* wait */

  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}