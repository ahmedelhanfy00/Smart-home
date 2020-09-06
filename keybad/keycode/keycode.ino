#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'D','2','0','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','3','#','1'}
};

byte rowPins[ROWS] = {5, 0, 1, A2}; //connect to the row pinouts of the keypad// coloumn 3,1 
byte colPins[COLS] = {9, A3, 7, A4}; //connect to the column pinouts of the keypad  // row 1 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  
   Serial.begin(9600);
}
int counter=0;
void loop(){
  
  char key = keypad.getKey();
  if (key=='0')
  {
    counter++;
  }
  
  if ((counter==4&&key=='D') ){
    
    Serial.println("success");
    counter=0;
  }
  else if (counter!=4&&key=='D') {Serial.print("crimnal");}
}
