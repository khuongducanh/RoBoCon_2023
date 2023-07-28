#include "PS2X_lib.h"
void  GoiLaiBien() {
  ps2x.read_gamepad();
  //gan bien cho nut nhan
  up    = ps2x.Button(PSB_PAD_UP);      
  down  = ps2x.Button(PSB_PAD_DOWN);  
  right = ps2x.Button(PSB_PAD_RIGHT);
  left  = ps2x.Button(PSB_PAD_LEFT); 

  L1 = ps2x.Button(PSB_L1);         
  R1 = ps2x.Button(PSB_R1);         
  L2 = ps2x.Button(PSB_L2);        
  R2 = ps2x.Button(PSB_R2);
  R3 = ps2x.Button(PSB_R3);
  L3 = ps2x.Button(PSB_L3);        

  pink =     ps2x.Button(PSB_PINK);
  red  =     ps2x.Button(PSB_RED);
  green =    ps2x.Button(PSB_GREEN);
  blue =     ps2x.Button(PSB_BLUE);
  
  traidoc =       ps2x.Analog(PSS_LY);
  traingang     = ps2x.Analog(PSS_LX);   
  phaidoc       = ps2x.Analog(PSS_RY);    
  phaingang     = ps2x.Analog(PSS_RX);  

  start  =   ps2x.Button(PSB_START); 
  select =   ps2x.Button(PSB_SELECT);  

  traidoc  = map(traidoc  ,0,255,-1023,1023);
  traingang= map(traingang,0,255,-1023,1023);
  phaidoc  = map(phaidoc  ,0,255,-1023,1023);
  phaingang= map(phaingang,0,255,-1023,1023);
  b1 = digitalRead(HT1);
  b2 = digitalRead(HT2);
  b3 = digitalRead(HT3);
  b4 = digitalRead(HT4);
  b5 = digitalRead(HT5);
  b6 = digitalRead(HT6);

  cambien1 = digitalRead(A8);
  cambien2 = digitalRead(A9);
  sensorA11 = digitalRead(A11);
  sensorA12 = digitalRead(A12);
  sensorA10 = digitalRead(A10);

  delay(20);
}


