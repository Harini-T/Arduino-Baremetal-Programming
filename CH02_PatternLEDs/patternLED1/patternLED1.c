#include<avr/io.h>
#include<util/delay.h>

void patternLED1(uint8_t oneByte){
	PORTD = oneByte;
	_delay_ms(100);
}

int main(){
	DDRD = 0xff;
	while(1){
		patternLED1(0b00001110);
		patternLED1(0b00010110);
		patternLED1(0b01001110);
		patternLED1(0b11000110);
		patternLED1(0b10101010);
		patternLED1(0b01010101);
		patternLED1(0b00110011);
		patternLED1(0b11001100);
		patternLED1(0b01101101);
		patternLED1(0b10010010);
		PORTD = 0;
		_delay_ms(1000);
	}
	return 0;
}