#include <LiquidCrystal.h>
#include <PS2X_lib.h>  
#include"Khaibaobien.h"
#include"LCD.h"
#include"linhtinh.h"
#include"dongcoban.h"
#include"Move.h"  
#include"hanhtrinh.h"
void setup(){
  Serial.begin(57600);
  lcd.begin(20, 4);
  #include "INandOUT.h"
}

void loop(){
  if(error == 1 ) return;
  else{
    Goilaibien();
    ps2x.read_gamepad(false, vibrate);
  if(R2){
      Goilaibien();
      
      Speed();                      //tangtoc
      Xilanhdien(green,blue);       //nang xilanhdien
      Nangvong(phaidoc,phaingang);  //nang long
      if(start){
        xung = pwm(130);
      }
    }
//**************************************
  else if(L2){
      //DemL1
      while(L1){
      DemL1++;
      while(L1){
      Goilaibien();
      Serial.println(DemL1);
      }
     }
     //Demselect
      while(select){
      DemSelect++;
      while(select){
      Goilaibien();
      if(select && DemSelect > 0){ 
        DemL1  = 0 ;
       }
     }
     Serial.println("reset dem ");
    }
  }
//*****************************************
    else{
      Goilaibien();
      ps2x.read_gamepad(false, vibrate);
      Nutdungdc(R3);   //dung khan cap dc ban   
      Resetboard(L3);  //Reset Board Arduino
      Move();          //binhthuong
      Check();         //kiemtra cong tac 
      Napvong(pink);   //nap vong
      Dogocban();      //bien tro do goc 
      dkdongco();      //dk dong co
      Hanhtrinh();     //nangvong
      Dcmoc()    ;     //dongcomocvong
    /*
      Serial.println(traidoc);
      Serial.println(traingang); 
      Serial.println(phaidoc);
      Serial.println(phaingang);*/
     
    }
  }
}
