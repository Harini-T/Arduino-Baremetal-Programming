#include<avr/io.h>
#include<util/delay.h>

#define DELAY 200

int main(){
	uint8_t i=0;
	DDRB = 0xff;
	
	while(1){
		while(i<7){
			PORTD = (1 << i);
			_delay_ms(DELAY);
			i++;
		}
		while(i>0){
			PORTD = (1 << i);
			_delay_ms(DELAY);
			i--;
		}
	}
	return 0;
}