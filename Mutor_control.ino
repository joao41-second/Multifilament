
 #include "main.h"


const float stepsPerUnitX = 350; 

 void configurarMotor(steper* motor, int stepPin, int dirPin) {
     motor->stepPin = stepPin;
     motor->dirPin = dirPin;
     pinMode(stepPin, OUTPUT);
     pinMode(dirPin, OUTPUT);
 }

 void moverMotor(steper* motor, double passos, int sentido,float feedrate_mm_per_min) {
    digitalWrite(motor->dirPin, sentido);
  float stepsPerSecond = (feedrate_mm_per_min * stepsPerUnitX) / 60.0;

  // Calcula o tempo de atraso entre passos em microsegundos
  long stepDelay = (long)(1000000.0 / stepsPerSecond);

 
  if(stepDelay < 40)
  {
    stepDelay = 40;
  }
  // Move o motor de passo pelo número especificado de passos
  for (double i = 0; i < passos/2; i++)
  {
    digitalWrite(motor->stepPin, HIGH);
    delayMicroseconds(stepDelay); // Ajuste o tempo conforme necessário para o seu motor
    digitalWrite(motor->stepPin, LOW);
    delayMicroseconds(stepDelay); // Ajuste o tempo conforme necessário para o seu motor
  }
 }
