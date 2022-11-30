#include <avr/io.h>                       
#include <util/delay.h>                    

#define DELAYTIME 45                                  
#define LED_PORT                PORTD
#define LED_PIN                 PIND
#define LED_DDR                 DDRD

int main(void) {

  uint16_t x = 0x1234;
  uint8_t y;
  LED_DDR = 0xff;               

 
  while (1) {

    x = 2053 * x + 13849;                
    y = (x >> 8) & 0b00000111;      
    LED_PORT ^= (1 << y);                            
    _delay_ms(100);

  }                                                
  return 0;
}