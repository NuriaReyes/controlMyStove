//stoveon
//levelgas
//gassensor
//temperature
//salidas
//gas
//chispa
const int led1Pin=8;
const int led2Pin=9;
const int led3Pin=10;
int potval = 0; 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  

  if(sensorValue<=3){
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
  }
  else if(sensorValue>=10 && sensorValue<=100){
     digitalWrite(8, HIGH);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
  }
  else if(sensorValue>=200 && sensorValue<=299){
     digitalWrite(9, HIGH);
     digitalWrite(10, LOW);
  }
  else if (sensorValue>=300){
     digitalWrite(10, HIGH);
  }
  
  
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}




