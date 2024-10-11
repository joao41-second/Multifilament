
#include "main.h"
#include <SoftwareSerial.h>

struct steper motorA;
struct steper motorB;

struct val step;

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

// Definir pinos RX e TX
const int rxPin = 9;
const int txPin = 10;
SoftwareSerial mySerial(rxPin, txPin);

char motA[10] = "mutorA";
char motB[10] = "mutorB";
 String motC = "mutorC";

float sepid = 300;

float F;
float E;

void setup() {
   Serial.begin(9600); // Inicia a comunicação serial no monitor serial
   mySerial.begin(9600); // Inicia a comunicação serial na taxa de 9600 baud
   Serial.println("a espera");
   configurarMotor(&motorA,StepA,DirA);
   configurarMotor(&motorB,StepB,DirB); 
   pinMode(8, INPUT);
   pinMode(15, INPUT);
   pinMode(16, OUTPUT);
   pinMode(8, OUTPUT);
   }

int cpar(const char *str1,const char*str2)
{
  int e = -1;
  while( ++e < 6  )
    {
      //Serial.print(conver[e]);
       if(str1[e] !=str2[e]){
        return(1);
        }
      }
      return(0);
}

void motor_start(steper mot_retira,steper mot_coloca)
{
    digitalWrite(8, 0);
  Serial.println("foi defenido outro filamento retirar o A" );
  moverMotor(&mot_retira,20000,1,sepid);
   delay(10);
   
  
  
    Serial.println("a por filamento  B" );
   moverMotor(&mot_coloca,20000,0,sepid);
  
}

double convertExtrusionToSteps(double extrusion_mm) {
    double steps = extrusion_mm *350;
    return steps;
}
 struct steper set;

void loop() {

  String mensagemRecebida;
  digitalWrite(8,1);
  if (mySerial.available() > 0) { // Verifica se há dados disponíveis na porta serial
    mensagemRecebida = mySerial.readStringUntil('\n'); // Lê a mensagem até a nova linha
    Serial.print("Mensagem recebida: "); // Imprime a mensagem recebida no monitor serial
    Serial.println(mensagemRecebida);
    char* conver = mensagemRecebida.c_str();
    int e = -1;

    int i = cpar(conver,motB);

   
    
    
     if(cpar(conver,motB) == 0)
     {
      Serial.println("o mtor B");
      set= motorB;
     }
     if(cpar(conver,motA) == 0)
     {
      Serial.println("o mtor A");
       set= motorA;
     }
     else if(mensagemRecebida == motC)
     {
     }
     
      
      split(conver,&F,&E);
          int dir = 0;
      if(E < 0)
      {
        E = -(E);
        dir = 1;
      }
        Serial.println("os passos");
      Serial.println(E);
      Serial.println(dir);
      Serial.println(F);
      Serial.println(convertExtrusionToSteps(E));
       digitalWrite(8,0);
      moverMotor(&set, convertExtrusionToSteps(E),dir,F);
       digitalWrite(8,1);
      E =0;
      dir = 0;
      

  }
   
    
    
      

}
