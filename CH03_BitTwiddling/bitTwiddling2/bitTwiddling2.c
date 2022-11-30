#include <avr/io.h>
#include <util/delay.h>

#define DELAY     100                                            

static inline uint8_t LFSR8_step(uint8_t random);
static inline uint16_t LFSR16(uint16_t random);

int main(void) {
  DDRD = 0xff;                                   
  uint16_t random = 123;           
  while (1) {            
    random = LFSR16(random);
    PORTD = (random >> 8);
    _delay_ms(DELAY);
  }                                                  
  return 0;
}

inline uint8_t LFSR8_step(uint8_t random) {
  
  uint8_t tap1, tap2, tap3, tap4;
  uint8_t newBit;
  tap1 = 1 & (random >> 3);
  tap2 = 1 & (random >> 4);
  tap3 = 1 & (random >> 5);
  tap4 = 1 & (random >> 7);

  newBit = tap1 ^ tap2 ^ tap3 ^ tap4;
  random = ((random << 1) | newBit);
  return (random);
}


inline uint16_t LFSR16(uint16_t random) {
  uint16_t tap1, tap2, tap3, tap4;
  uint16_t newBit;
  tap1 = 1 & (random >> 3);
  tap2 = 1 & (random >> 12);
  tap3 = 1 & (random >> 14);
  tap4 = 1 & (random >> 15);

  newBit = tap1 ^ tap2 ^ tap3 ^ tap4;
  random = ((random << 1) | newBit);
  return (random);
}