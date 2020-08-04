#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>



void Init(){

  DDRD |= B01000000;
  UCSR0B=(1<<RXEN0); //enable receiver
  UBRR0L=103; //baud 9600
}


void Task()
{ while(1)
{
  while(!(UCSR0A & (1<<RXC0))); // se asteapta primirea datelor,1 sau 0
  switch(UDR0)
  { 
    case '1' : PORTD |=B01000000;
               break;
  
    case '0' : PORTD &=B10111111;
               break;
               

    default: break;
}
}
}

int main()
{ Init();
  Task();
}
