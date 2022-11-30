#include<avr/io.h>
#include <util/delay.h>
#define DELAYTIME2

uint8_t arr[]={
	0b10101010,
	0b01010101,
	0b11001100,
	0b00110011,
	0b10010010,
	0b01101101,
	0b11100011,
	0b00011100,
	0b11101101,
	0b00010010,
	0b10110010,
	0b01001101
};

int main(){
	DDRD = 0xff;
	uint8_t i;
	while(1){
		for(i=0;i<sizeof(arr);i++){
			PORTD = arr[i];
			_delay_ms(100);
		}
		PORTD = 0;
	}
	return 0;
	
}