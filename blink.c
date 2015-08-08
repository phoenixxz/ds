#include <wiringPi.h>
int main(void)
{
  wiringPiSetup() ;
  pinMode (1, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
  digitalWrite(1, HIGH);delay (500) ;
  for(;;) 
  {
    digitalWrite(4, HIGH);delay (1000) ;
    digitalWrite(4, LOW);delay (50) ;
  }
}




