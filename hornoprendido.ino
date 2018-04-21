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
  pinMode(11, OUTPUT);
  
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  

  if(sensorValue>=200){
     digitalWrite(11, HIGH);
  }
  else if (sensorValue<=199){
     digitalWrite(11, LOW);
  }

  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}




