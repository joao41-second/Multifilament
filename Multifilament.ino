
#include "main.h"

struct steper motorA;
struct steper motorB;

const int StepA = 2;
const int DirA = 5;
const int StepB = 3;
const int DirB = 6;
const int StepC = 4;
const int DirC = 7;

int tempA = 0;
int tempB = 0;
int value_filamenteA = 0;
int value_filamenteB = 0;

void setup() {
configurarMotor(&motorA,StepA,DirA);
configurarMotor(&motorB,StepB,DirB);
Serial.begin(9600); 
pinMode(9, INPUT);
pinMode(15, INPUT);
pinMode(16, OUTPUT);
}

void loop() {
 

value_filamenteA = digitalRead(14);
value_filamenteB = digitalRead(15);

//Serial.print("filamento a por ou a retirar" );
 digitalWrite(9, 1);
 
 //Serial.println(value_filamenteA );
// moverMotor(&motorA,1000,0);

if (value_filamenteA == 0 && tempA == 1 )
{
  digitalWrite(9, 0);
  Serial.println("foi defenido outro filamento retirar o A" );
  moverMotor(&motorA,10000,1);
   delay(10);
   value_filamenteB = digitalRead(15);
  if(value_filamenteB == 1)
  {
    Serial.println("a por filamento  B" );
    moverMotor(&motorB,10000,0);
  }

}
if (value_filamenteB == 0 && tempB == 1)
{
  digitalWrite(9, 0);
  Serial.println("foi defenido outro filamento retirar o B" );
  moverMotor(&motorB,10000,1);
  delay(10);
   if(value_filamenteA == 1 )
   {
    Serial.println("a por filamento  A" );
    moverMotor(&motorA,10000,0);
    
  }
 
}

tempA = value_filamenteA;
tempB = value_filamenteB;

delay(1000); // delay for 1 second





}
