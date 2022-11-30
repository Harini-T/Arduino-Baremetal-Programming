#include <avr/io.h>                     
#include <util/delay.h>                     

#define DELAYTIME 85    

int main(void) {
  uint8_t i;
  DDRD = 0xff;                  
  
  while (1) {                                             

    for (i = 0; i < 7; i++) {                   
      PORTD |= (1 << i);                              
      _delay_ms(DELAYTIME);                                    

      PORTD |= (1 << (i + 1));                
      _delay_ms(DELAYTIME / 2);

      PORTD &= ~(1 << i);                            
    }

    for (i = 7; i > 0; i--) {                   
      PORTD |= (1 << i);
      _delay_ms(DELAYTIME);

      PORTD |= (1 << (i - 1));                 
      _delay_ms(DELAYTIME / 2);

      PORTD &= ~(1 << i);                            
    }

  }                                                 
  return 0;
}                                                          