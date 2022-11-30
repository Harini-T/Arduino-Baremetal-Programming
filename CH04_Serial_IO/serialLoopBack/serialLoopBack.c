#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"



int main(void) {
  char serialCharacter;
  DDRD = 0b11000000;
  DDRB = 0b00111111;                            
  initUSART();
  printString("Hello World!\r\n");                          

  while (1) {
    serialCharacter = receiveByte();
    transmitByte(serialCharacter);
    PORTB = serialCharacter>>2;
	PORTD = serialCharacter<<6;                  
  }                                                
  return 0;
}