#include <SoftwareSerial.h>
SoftwareSerial BT (0,1);
char BTdata;
void setup() 
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);  
Serial.begin(9600);
BT.begin(9600);  

}

void loop() 
{if(Serial.available()>0){
  BTdata=BT.read();
  Serial.println(BTdata);
  if (BTdata=='0'){digitalWrite(2,HIGH);}
  if (BTdata=='1'){digitalWrite(2,LOW);}
  if (BTdata=='2'){digitalWrite(3,HIGH);}
  if (BTdata=='3'){digitalWrite(3,LOW);}
  if (BTdata=='4'){digitalWrite(4,HIGH);}
  if (BTdata=='5'){digitalWrite(4,LOW);}
  if (BTdata=='4'){digitalWrite(4,HIGH);}
  if (BTdata=='5'){digitalWrite(4,LOW);}
  
}}
