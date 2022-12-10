#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>

int main()
{
	DDRD = 0xff;
	
	while(1){
		if(bit_is_clear(PINB, PB2)){
			PORTD = 0b00111100;
		}
		else{
			PORTD = 0b11000011;
		}
		_delay_ms(200);
	}
  return 0;
}