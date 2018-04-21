//levelgas
//gassensor
//temperatura
const int gas = 30;         //output
const int chispa = 32;      //output

const int reset = 24;       //input
const int stoveon = 22;     //input

int stoveonstate = 0;
int resetstate =0;
int contador =0;
int timeron = 0;
int timer = 2000;

const int led1=8;
const int led2=9;
const int led3=10;
int nivelestufa = 0; 

const int ledtemp=11;
int temphorno = 0; 

const int nivelgas=12;
int gass = 0;

void setup() {
  pinMode(stoveon, INPUT);
  pinMode (reset, INPUT);
  pinMode(chispa, OUTPUT);
  pinMode(gas, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  stoveonstate = digitalRead(stoveon);
  resetstate = digitalRead(reset);
  int nivelestufa = analogRead(A0);
  int temphorno = analogRead(A1);
  int gass = analogRead(A2);
  
  if (stoveonstate == HIGH && timeron == 0) {
    digitalWrite(gas, HIGH);                                          // Activar gas
    
    if (contador == 0){                                               // Activar chispa para generar flama
    delay (400);
    digitalWrite(chispa, HIGH);
    delay (600);
    digitalWrite(chispa, LOW);
    contador ++;                     }

    if (timer != 0){
      delay (timer);
      digitalWrite(gas, LOW);
      timeron ++;    }}
    if(nivelestufa<=3){
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
  }
  else if(nivelestufa>=10 && nivelestufa<=100){
     digitalWrite(8, HIGH);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
  }
  else if(nivelestufa>=200 && nivelestufa<=299){
     digitalWrite(9, HIGH);
     digitalWrite(10, LOW);
  }
  else if (nivelestufa>=300){
     digitalWrite(10, HIGH);
  }


  if(temphorno>=200){
     digitalWrite(11, HIGH);
  }
  else if (temphorno<=199){
     digitalWrite(11, LOW);
  }


  if(gass>=200){
     digitalWrite(12, HIGH);
  }
  else if (gass<=199){
     digitalWrite(12, LOW);
  }
  
  Serial.println(nivelestufa);
  delay(1);        // delay in between reads for stability

 
    
 
   if (stoveonstate == LOW) {
    digitalWrite(gas, LOW);
    digitalWrite(chispa, LOW);                 }

  if (resetstate == HIGH){
    contador = 0;
    timeron = 0;
  }

}

