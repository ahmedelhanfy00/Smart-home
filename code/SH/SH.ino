#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL Serial 
#define REMOTEXY_SERIAL_SPEED 9600 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,8,0,0,0,139,0,8,24,0,
  2,1,28,6,22,11,64,26,31,16,
  79,78,0,79,70,70,0,2,1,53,
  6,22,11,2,26,31,31,79,78,0,
  79,70,70,0,2,1,77,6,22,11,
  2,26,31,31,79,78,0,79,70,70,
  0,2,1,3,6,22,11,2,26,31,
  31,79,78,0,79,70,70,0,2,1,
  52,51,22,11,2,26,31,31,79,78,
  0,79,70,70,0,2,1,27,51,22,
  11,2,26,31,31,79,78,0,79,70,
  70,0,2,1,2,51,22,11,2,26,
  31,31,79,78,0,79,70,70,0,2,
  1,77,51,22,11,2,26,31,31,79,
  78,0,79,70,70,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_4; // =1 if switch ON and =0 if OFF 
  uint8_t switch_5; // =1 if switch ON and =0 if OFF 
  uint8_t switch_6; // =1 if switch ON and =0 if OFF 
  uint8_t switch_7; // =1 if switch ON and =0 if OFF 
  uint8_t switch_8; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_SWITCH_1 5
#define PIN_SWITCH_2 6
#define PIN_SWITCH_3 7
#define PIN_SWITCH_4 4
#define PIN_SWITCH_6 9
#define PIN_SWITCH_7 8


void setup()  
{ 
  RemoteXY_Init ();  
   
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  pinMode (PIN_SWITCH_4, OUTPUT);
  pinMode (PIN_SWITCH_6, OUTPUT);
  pinMode (PIN_SWITCH_7, OUTPUT);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_6, (RemoteXY.switch_6==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_7, (RemoteXY.switch_7==0)?LOW:HIGH);
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
