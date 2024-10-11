#include "main.h"

void split(char *str,float *F,float *E)
{
  int i = -1;
  int save = 0;
  int seconf = 0;
  char F_char[50];
  F_char[49] = '\0';
  char E_char[50];
  E_char[49] = '\0';
  while(str[++i] != '\0')
  {
     
    if(str[i] == 'F')
    {
      seconf = 0;
      save = i + 1;
      while( str[save] != ' ' && str[save] != '\0'  )
      {
        
        F_char[seconf] = str[save];
        save++; 
        seconf++;
      }
    
        *F = atof(F_char);
    }
    if(str[i] == 'E')
    {
      seconf = 0;
      save = i+1;
      while(str[save] != '\0' && str[i] != ' ')
      {
        E_char[seconf] = str[save];
        save++;  
        seconf++;
      }
      *E = atof(E_char);;
    }
  }
}