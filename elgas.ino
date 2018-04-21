//stoveon
//levelgas
//gassensor
//temperature
//salidas
//gas
//chispa
const int ledtemp=11;
int potval = 0; 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A2);
  

  if(sensorValue>=200){
     digitalWrite(12, HIGH);
  }
  else if (sensorValue<=199){
     digitalWrite(12, LOW);
  }

  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}




