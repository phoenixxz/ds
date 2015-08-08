#include <wiringPi.h>
#include <stdio.h>
int main(void)
{
  wiringPiSetup() ;
  pinMode (1, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
  //enable
  digitalWrite(1, HIGH);
  printf("........\n");
  //digitalWrite(4, HIGH);delay (1000) ;
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);delay (10000) ;

  for(;;) 
  {
    digitalWrite(4, HIGH);delay (1000) ;
    digitalWrite(4, LOW);delay (50) ;
  }
}


void turn_left()
{
}

void turn_right()
{
}

void forward()
{
}
void backward()
{
}
