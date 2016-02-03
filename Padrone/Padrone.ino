byte rx2[2];
byte rx3[2];
int controlloValori2 = 0;
int controlloValori3 = 0;
byte cazzomene2;
byte tmp2;
byte cazzomene3;
byte tmp3;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
}

void loop() {

    tmp2=cazzomene2;
    if(Serial2.available()>0){
      cazzomene2=Serial2.read();
      if(tmp2==cazzomene2)
      {
        controlloValori2++;
        if(controlloValori2==3) {
          cazzomene2 = 0;
          }
        } 
        else
        {
         controlloValori2 = 0;
        }
 
    Serial.print("\t");
    Serial.print(cazzomene2);
    }
    tmp3=cazzomene3;
    if(Serial3.available()>0){
      cazzomene3=Serial3.read();
      if(tmp3==cazzomene3)
      {
        controlloValori3++;
        if(controlloValori3==3) {
          cazzomene3 = 0;
          }
        } 
        else
        {
         controlloValori3 = 0;
        }
 
    Serial.print("\t");
    Serial.print(cazzomene3);
    
  Serial.println();
    }
}
