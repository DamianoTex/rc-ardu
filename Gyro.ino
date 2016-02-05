#include "gy521.h"
#include "Wire.h"

gy521 Pippo('x');


float alfa=0;

float beta;

int delta;

float offset;

  void setup() 
  {
    Serial.begin(9600);
    
    Pippo.set(1000);              //250 500 1000 2000
    offset = Pippo.setGyro();  // ci mette 2sec, mantenere fermo il giroscopio per questo tempo   (puoi calcolarlo una volta e poi metterlo come costante)
    
    Pippo.setComp();  //setta lo Zero della Bussola
  }

  void loop() 
  {

   alfa= Pippo.gyroA(alfa,offset) ;

   beta=Pippo.compass();
   
   Serial.print((int)alfa);
   Serial.print("\t");
   Serial.print((int)beta);
   Serial.println();
   
   delay(5);

  }
