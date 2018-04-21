const int led1=8;
const int led2=9;
const int led3=10;
int nivelestufa = 0; 

const int ledtemp=11;
int temphorno = 0; 

const int nivelgas=12;
int gas = 0; 


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
}

void loop() {
  // read the input on analog pin 0:
  int nivelestufa = analogRead(A0);
  int temphorno = analogRead(A1);
  int gas = analogRead(A2);
  
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


  if(gas>=200){
     digitalWrite(12, HIGH);
  }
  else if (gas<=199){
     digitalWrite(12, LOW);
  }
  
  Serial.println(nivelestufa);
  delay(1);        // delay in between reads for stability
}




