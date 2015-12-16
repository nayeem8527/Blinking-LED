#include<avr/io.h>
#include<util/delay.h>

int main()
{
  DDRB |= 0x20;
  while(1)
  {
    PORTB ^= 0x20;
    _delay_ms(2000);
  }
  return 0;
}

