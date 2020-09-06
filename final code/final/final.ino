#include <Keypad.h>
#include <SoftwareSerial.h>
SoftwareSerial BT (0,1);
char BTdata;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'D','2','0','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','3','#','1'}
};

byte rowPins[ROWS] = {5, 0, 1, A0}; //ORANGE5 WHITE 7 BLUE 9 
byte colPins[COLS] = {9, A1, 7, A2}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int smokeA0 = A3;
int sensorThres = 100;
int room1 = 2 ; 
int room2 = 3 ; 
int bathroom = 4 ; 
int kitchen = 6 ; 
int road = 8 ; 
int hall1 = 10 ; 
int hall2 = 11 ; 
void setup()
{
pinMode(room1,OUTPUT);
pinMode(room2,OUTPUT);
pinMode(bathroom,OUTPUT);
pinMode(kitchen,OUTPUT);
pinMode(road,OUTPUT);
pinMode(hall1,OUTPUT);
pinMode(hall2,OUTPUT);
pinMode(smokeA0, INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
BT.begin(9600);  
}
int counter=0;

void loop()
{
  
  char key = keypad.getKey();
  if (key=='0')
  {
    counter++;
  }
  
  if ((counter==4&&key=='D') ){
    Serial.println("success"); 
    digitalWrite(room1,HIGH);
    delay(500);
    digitalWrite(room1,LOW);
    delay(500);
  while (1){ 
    int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(13, HIGH);
   
  }
  else
  {
    
    digitalWrite(13, LOW);
   
  }
  if(Serial.available()>0){
     
  BTdata=BT.read();
  Serial.println(BTdata);
  if (BTdata=='A'){digitalWrite(room1,HIGH);}
  if (BTdata=='a'){digitalWrite(room1,LOW);}
  if (BTdata=='B'){digitalWrite(room2,HIGH);}
  if (BTdata=='b'){digitalWrite(room2,LOW);}
  if (BTdata=='C'){digitalWrite(bathroom,HIGH);}
  if (BTdata=='c'){digitalWrite(bathroom,LOW);}
  if (BTdata=='D'){digitalWrite(kitchen,HIGH);}
  if (BTdata=='d'){digitalWrite(kitchen,LOW);}
  if (BTdata=='E'){digitalWrite(road,HIGH);}
  if (BTdata=='e'){digitalWrite(road,LOW);}
  if (BTdata=='F'){digitalWrite(hall1,HIGH);}
  if (BTdata=='f'){digitalWrite(hall1,LOW);}
  if (BTdata=='G'){digitalWrite(hall2,HIGH);}
  if (BTdata=='g'){digitalWrite(hall2,LOW);}   
  }}}
  else if (counter!=4&&key=='D') 
  {
    Serial.print("crimnal");
    }
   }
