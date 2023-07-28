#include <LiquidCrystal.h>
#include <PS2X_lib.h>  
#include <Eeprom24Cxx.h> 
#include "KhaiBaoBien.h" //define, int, khai bao
#include "Call.h"        //goilaibien ps2                                                                                                                                                                       *
#include "LCD.h"         //hienthi                                                                                       
#include "Move.h"        //dichuyen 
#include "Dongcoban.h"   //xung dc ban                                                                                  
#include "Encoder.h"     //Cam bien Encoder
#include "6Relay.h"      //Cong tac hanh trinh ket hop module relay
#include "linhtinh.h"    //những chương trình còn lại 
#include "cachdungnut.h"
#include "KhoiChayEEPROM.h"
void setup()
{
  //led7doan4so***
  // display.setBrightness(4);
  // display.clear();
  //***************
  Serial.begin(57600);lcd.begin(20, 4);
  #include "InputAndOutput.h"
  //setup pins and settings: GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_CS, PS2_DAT, pressures, rumble);
  type = ps2x.readType();
  switch (type) {//Ket noi PS2
    case 0:
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Disconnected");
      lcd.setCursor(0, 1);
      lcd.print("Please try again...");
      Serial.println("Disconnected");
      break;
    case 1:
      lcd.clear();  
      lcd.setCursor(0, 0);
      lcd.print("Connected");
      Serial.println("Connected");
      break;
  }
}

void loop()
{ 
  if (error == 1) return;
  //DualShock Controller
  else{  
    GoiLaiBien();
    ps2x.read_gamepad(false, vibrate);
    //****************************************************
    if(R2){ 
      Speed();              //Giu R2 tang toc di chuyen    
      Xilanhdien(green,blue); //nang xilanhdien           
      while(red){
        DemRed++;
        while(red){
          GoiLaiBien();
          RUN1(); //lay vong bang encoder
          RUN2(); //di chuyen cac cot
        }
      }
      Chinhlaikepvong(phaidoc,phaingang); //analog right chinh kep vong
      Dogocban();           //Đo góc bắn
    }
    //******************************************************
else if(L2){
    //DemL1
    while(L1){
      DemL1++;
    while(L1){
        GoiLaiBien();
        Serial.println(ps2x.Button(PSB_L1) );
      }
          

    }
    //Chinhlaikepvong(phaidoc,phaingang); //analog right chinh kep vong
    //Nhan select reset cac bien
  while(select){
    DemSelect++;
    while(select){
      GoiLaiBien();
      if(select && DemSelect > 0){ 
        DemHT1 = 0 ;
        DemHT2 = 0 ;
        DemL1  = 0 ;
        DemRed = 0 ;
      }
      Serial.println(ps2x.Button(PSB_SELECT) );
    }
  }
  Read_Write_EEPROM(green,pink);//cột 1 green, cột 2 pink
  vovo(red); //trong tổ hợp L2
}
//********************************************************
    else{
      //xung 133 : goc 1845
      //xung 130 : goc 1874
      //xung 133 : goc 1906 cot 1 va cot 3 . cot 2 : goc 1915

      //cot 1 (goc : 4882
       // : 132 )
      //cot loai 1 : xung 140 , goc 4843
      //cot loai 2 : xung 155- goc 7960 || 155 - 7919
      kep();
      ps2x.read_gamepad(false, vibrate);
      dkdongco();           //dk dong co
      Move();               //di chuyen mac dinh
      HanhTrinhGapVong();   //Chay co cau gap vong
      Napvong(pink);        //napvong
      gocEEPROM(HIGH);      //khi đo đúng góc tự động dừng
      Resetboard(L3);       //Reset toàn bộ board arduino
      Nutdungdc(R3);        //Dừng khẩn cấp động cơ bắn 
     // Khunhieulcd(red);
      //reset ấn lần 3 tổ hợp R2 && Red
      if(DemRed==3){lcd.setCursor(0, 3); lcd.print("         ");counter=0;}
      DoKhoangCach(counter);
      if(red&&pink&&blue&&green){
        lcd.begin(20, 4);
        lcd.clear();
      }
    }
  }
}