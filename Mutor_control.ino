
#include "main.h"

void configurarMotor(steper* motor, int stepPin, int dirPin) {
    motor->stepPin = stepPin;
    motor->dirPin = dirPin;
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void moverMotor(steper* motor, int passos, int sentido) {
    digitalWrite(motor->dirPin, sentido);
    for (int i = 0; i < passos; i++) {
        digitalWrite(motor->stepPin, HIGH);
        delayMicroseconds(500); // Ajuste o tempo conforme necessário para o seu motor
        digitalWrite(motor->stepPin, LOW);
        delayMicroseconds(500); // Ajuste o tempo conforme necessário para o seu motor
    }
}
