/*******
 
 All the resources for this project:
 https://www.hackster.io/Aritro

*******/



int smokeA0 = A3;
int sensorThres = 100;

void setup() {
  
  
  pinMode(smokeA0, INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(3, HIGH);
   
  }
  else
  {
    
    digitalWrite(3, LOW);
   
  }
 
}
