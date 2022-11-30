#include <avr/io.h>
#include <util/delay.h>

#define DELAY		200

#define LED_PORT	PORTD
#define LED_DDR		DDRD

uint8_t arr1[]={
	0b01110000,
	0b00011000,
	0b11111101,
	0b10110110,
	0b00111100,
	0b00111100,
	0b00111100,
	0b10110110,
	0b11111101,
	0b00011000,
	0b01110000
};

uint8_t arr2[]={
	0b00001110,
	0b00011000,
	0b10111101,
	0b01110110,
	0b00111100,
	0b00111100,
	0b00111100,
	0b01110110,
	0b10111101,
	0b00011000,
	0b00001110
};

void pause(){
	uint8_t i;
	for(i=0;i<5;i++){
		_delay_ms(DELAY);
	}
}

void patternDisplay(uint8_t arr[], uint8_t numberRows){
	uint8_t i;
	for(i=0;i<numberRows;i++){
		LED_PORT = arr[i];
		_delay_ms(DELAY);
	}
	pause();
}

int main(){
	LED_DDR = 0xff;
	while(1){
		patternDisplay(arr1, sizeof(arr1));
		patternDisplay(arr2, sizeof(arr2));
	}
	return 0;
}