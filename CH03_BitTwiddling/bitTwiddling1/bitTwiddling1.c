#include <avr/io.h>                        
#include <util/delay.h>                     

#define DELAYTIME 85                                   
#define LED_PORT                PORTD
#define LED_DDR                 DDRD

int main(void) {

 
  uint8_t i=0;
  LED_DDR = 0xff;               
  
  while (1) {

    while (i < 7) {
      LED_PORT = (1 << i);                 
      _delay_ms(DELAYTIME);                                 
      i = i + 1;                              
    }

    while (i > 0) {
      LED_PORT = (1 << i);                 
      _delay_ms(DELAYTIME);                                    
      i = i - 1;                          
    }

  }                                                 
  return 0;
}