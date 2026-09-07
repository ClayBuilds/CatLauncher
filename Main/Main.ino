#include <Stepper.h>


const int DCen = 12;    //pin1 on L293D (1)
const int DCin1 = 11;   //pin2 on L293D (1)
const int DCin2 = 10;   //pin7 on L293D (1)

const int STPen = 14;   //pin 1 on L293D (2)
const int STPin1 = 15;  //pin 2 on L293D (2)
const int STPin2 = 16;  //pin 7 on L293D (2)
const int STPin3 = 17;  //pin 10 on L293D (2)
const int STPin4 = 18;  //pin 15 on L293D (2)

int i = 0;

bool killallhumans = true;

const double stpangle = 3.75;
const double spr = 360/stpangle;

Stepper s = Stepper(spr, 15, 16, 17, 18);

void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);         //turn on board LED
    digitalWrite(LED_BUILTIN, HIGH);

    pinMode(DCen, OUTPUT);              //setup outputs
    pinMode(DCin1, OUTPUT);
    pinMode(DCin2, OUTPUT);

    pinMode(STPen, OUTPUT);
    pinMode(STPin1, OUTPUT);
    pinMode(STPin2, OUTPUT);
    pinMode(STPin3, OUTPUT);
    pinMode(STPin4, OUTPUT);

    s.setSpeed(15);                 //define stepper speed
}

void loop()
{
  delay(5000);

  digitalWrite(STPen, HIGH);         //rotate stepper to release ball
  s.step(spr/4);    
  digitalWrite(STPen, LOW);
  delay(250);

  digitalWrite(DCen, HIGH);         //enable DC motor

  digitalWrite(DCin1, HIGH);        //rotate motor backwards slowly 
  analogWrite(DCin2, 100);
  delay(250);

  digitalWrite(DCin1, LOW);         //pause motor
  digitalWrite(DCin2, LOW);
  delay(100);
  
  digitalWrite(DCin1, LOW);         //Rapid ramp up DC motor with PWM
  for(i=0;i<=255;i+=8)             
  {
    analogWrite(DCin2, i);
    delay(1);
  }
  digitalWrite(DCin2, HIGH);

  delay(1000);                      //Leave DC motor running for 1 second

  for(i=255;i>=0;i--)               //Ramp down DC  motor
  {
    analogWrite(DCin2, i);
    delay(5);
  }
  
  digitalWrite(DCen, LOW);          //disable DC motor
  digitalWrite(DCin1, LOW);
  digitalWrite(DCin2, LOW);

  

  
}
