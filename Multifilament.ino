
// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech
#include "main.h"





struct steper motorA;




const int StepA = 2;
const int DirA = 5;
const int StepB = 3;
const int DirB = 6;
const int StepC = 4;
const int DirC = 7;


int value_filamente = 0;



void setup() {
configurarMotor(&motorA,StepA,DirA);

}

void loop() {
 

value_filamente = analogRead(A2);
 moverMotor(&motorA,1000,1);
 

delay(1000); // delay for 1 second





}
