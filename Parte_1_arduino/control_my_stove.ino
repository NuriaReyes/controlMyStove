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
int timer = 1000;


void setup() {
  pinMode(stoveon, INPUT);
  pinMode (reset, INPUT);
  pinMode(chispa, OUTPUT);
  pinMode(gas, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  stoveonstate = digitalRead(stoveon);
  resetstate = digitalRead(reset);
  
  if (stoveonstate == HIGH && timeron == 0) {
    digitalWrite(gas, HIGH);                                          // Activar gas
    
    if (contador == 0){                                               // Activar chispa para generar flama
    delay (400);
    digitalWrite(chispa, HIGH);
    delay (400);
    digitalWrite(chispa, LOW);
    contador ++;                     }

    if (timer != 0){
      delay (timer);
      digitalWrite(gas, LOW);
      timeron ++;    }
    }
 
  else {
    digitalWrite(gas, LOW);
    digitalWrite(chispa, LOW);                 }

  if (resetstate == HIGH){
    contador = 0;
    timeron = 0;
  }

}
