#include <avr/io.h>
#include <util/delay.h>

int main()
{
	uint8_t buttonWasPressed;
	PORTB = (1<<PB2);
	DDRD = 0b00000001;

	while(1){
		if(bit_is_clear(PINB, PB2)){
			if(buttonWasPressed==0){
				PORTD ^= (1 << PD0);
				buttonWasPressed=1;
			}
		}
		else{
			buttonWasPressed=0;
		}
	}
	return 0;
}