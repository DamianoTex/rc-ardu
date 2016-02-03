
#define AT 2                               //AT 2 AT328 davanti    AT 3 AT328 dietro
#define sample 10                           //n campioni per la media

int j, i;                                  //variabili per i cicli di lettura di 3x sensore valori
int media[12];                             //vettore con medie delle tre letture
int maxm[2] = {0, 0};                       //vettore da stampare in seriale a Master 0=potenza, 1=posizione
byte outByte;
int posi[2][12] = {                        //vettore che in base alla lettura maggiore indica il settore della palla
  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 22, 23, 24, 1, 2, 3, 4, 5, 6, 7, 8
};


void setup() {

  Serial.begin(9600);

}

void loop()
{
  for (j = 0 ; j < sample ; j++)                              //cicli di lettura, legge 3 valori
  { //per sensore e ne calcola la media
    for (i = 0 ; i < 12 ; i++)
    {
      if (j != (sample - 1))
      {
        media[i] += pulseIn(2 + i, LOW, 800);
      }
      else
      {
        media[i] = (pulseIn(2 + i, LOW, 800) + media[i]);
        media[i] /= sample;
        
      }
    }
  }

  for ( i = 0 ; i < 12 ; i++)                                //calcola il massimo e lo salvo in maxm[0]=forza
  { //salvo l'indice in maxm[1]=indice in base al controllore
    if (media[i] > maxm[0])
    {
      maxm[0]=media[i];
      maxm[1] = i;
      
    }
  }
  outByte = posi[0][maxm[1]];
  Serial.write(outByte);

  //maxm[0]-=200; //200

  //Serial.println(outByte);
  //Serial.write(outByte);
  outByte=0;
  maxm[1]=0;
  maxm[0]=0;
}

