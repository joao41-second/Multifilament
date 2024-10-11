
#ifndef MAIN_H
#define MAIN_H

 struct steper{
  int stepPin;
  int  dirPin;
  int passos;
};


struct val
{
  int F;
  int E;
};

char	**ft_split(char const *s, char c);



void configurarMotor(steper* motor, int stepPin, int dirPin);
/**
* @brief configure pinut of de steper motors
* @param motor variabel motor pointer set;
* @param stepPin pin to control to motor step
* @param dirPin pin to control  direction of the motor 
*/

void moverMotor(steper* motor, int passos, int sentido);
/**
* @brief moviment motor slect 
* @param variabel represent motro to move 
* @param passos number steps to give the motor
* @param sentido direction of rotate motor 
*/


#endif 
