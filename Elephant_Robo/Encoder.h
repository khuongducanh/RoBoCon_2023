#include "Arduino.h"
//Encoder 1
void ai0() {if (digitalRead(21) == LOW) {counter++;} else {counter--; }}
void ai1() {if (digitalRead(20) == LOW) {counter--;} else {counter++; }}
//Encoder 2
void bi0() {if (digitalRead(18) == LOW) {temp++;}     else {temp--; }}
void bi1() {if (digitalRead(19) == LOW) {temp--;}     else {temp++; }}

//Do khoang cach tu du lieu encoder
void DoKhoangCach(long BienDem) {  
  distance = ((pi * d) / n) * BienDem;
  lcd.setCursor(0, 3); 
  lcd.print(distance); 
  lcd.setCursor(6, 3); 
  lcd.print("cm");
}

void RUN1(){
  if (red && !pink  && !blue && !green && !down){
    //chay lay vong and bam tuong
  while (red == HIGH && !pink && !blue && !green && DemRed <=3){
      DoKhoangCach(counter);
      GoiLaiBien();
      ShowLCD("RUN1    ");
      //Serial.println(distance);
    //nhan lan 1 nut R2+ Red
    if      (distance <= 15 && DemRed == 1)                   {dichuyen (  LOW , HIGH , HIGH , LOW, 18, 20, 18, 20);}
    else if ((distance > 15 && distance <= 30 && DemRed  == 1)){dichuyen(  LOW , HIGH , HIGH , LOW, 20, 23, 20, 23);}
    else if (distance > 30 && distance  <= 375 && DemRed == 1){dichuyen (  LOW , HIGH , HIGH , LOW, 30, 36, 30, 36);} 
    else if (distance > 375 && distance <= 380 && DemRed == 1){dichuyen (  LOW , HIGH , HIGH , LOW, 20, 25, 20, 25);} 
    else if (distance > 385 && distance <= 390&& DemRed == 1){dichuyen (   LOW , HIGH , HIGH , LOW, 15, 23, 15, 23);} 
    else if (distance > 390 && distance <= 400 && DemRed == 1){dichuyen (  LOW , HIGH , HIGH , LOW, 8, 12, 8, 12);}  
    else if (distance > 400 && DemRed == 1)                   {dichuyen (  LOW , HIGH , HIGH , LOW, 2, 2, 2, 2);}
    if( distance >250 && distance <=300 && DemRed == 1 ){digitalWrite(xilanhnangcocau,HIGH);}
    if(sensorA11 == 0 && DemRed == 1)                   {digitalWrite(xilanhkepvong , HIGH);}
    Serial.print("C==");
    Serial.println( digitalRead(A11));
    //nhan lan 2 nut R2+Red xoay lai 
    if      (distance > 223 && distance <= 550 && DemRed == 2)  {dichuyen( HIGH , LOW  , LOW  , HIGH, 15, 27, 27, 10);}
    else if (distance > 150 && distance <= 223 && DemRed == 2)  {dichuyen( HIGH , LOW  , LOW  , HIGH, 10, 10, 10, 10);}     
    else if (distance < 150 && DemRed == 2)                     {dichuyen( HIGH , LOW  , LOW  , HIGH,  2,  2,  2,  2);}
    //giam dan speed and dung o cot 1
    if (red == LOW && !pink && !blue && !green) {dichuyen( HIGH , LOW  , LOW  , HIGH, 2, 2, 2, 2); break;
      }
    }
  }
}
void RUN2() {
//DoKhoangCach(temp);
  Serial.println(DemRed);
if (red && !pink && !blue && !green && !down) {
   // Serial.println(distance);
    while (red == HIGH && !pink && !blue && !green && DemRed>=3)
    {
    DoKhoangCach(counter);
    GoiLaiBien();
    ShowLCD("RUN2    ");
  //nhan lan 3
//reset bien dem encoder 1 va encoder 2
//nhan lan 4 di chuyen tu cot 1 den cot 3 
      if (distance > -25  && DemRed == 4)                       {dichuyen (HIGH , HIGH , LOW  , LOW  ,20,15,20,15);}
      else if(distance < -25 && distance >= -485 && DemRed ==4) {dichuyen (HIGH , HIGH , LOW  , LOW  ,35,26,35,26);}
      else if(distance < -485 && distance >= -500 && DemRed ==4){dichuyen (HIGH , HIGH , LOW  , LOW  ,25,15,25,15);}  
      else if(distance < -500 && distance >= -519 && DemRed ==4){dichuyen (HIGH , HIGH , LOW  , LOW  ,15,15,15,15);}
      else if(distance < -519 && DemRed ==4)                    {dichuyen (HIGH , HIGH , LOW  , LOW  ,2,2,2,2);}    //648,638
//nhan lan 5 di chuyen tu cot 3 ve cot 2
      if      (distance <= -530 && DemRed == 5)                   {dichuyen (  LOW  , LOW  , HIGH, HIGH, 20, 25, 20, 25);}
      else if (distance > -519 && distance <= -300 && DemRed == 5){dichuyen ( LOW   , LOW  , HIGH, HIGH, 25, 30, 25, 30);} 
      else if (distance > -300 && distance <= -290 && DemRed == 5) {dichuyen ( LOW   , LOW  , HIGH, HIGH, 25, 20, 25, 20);} 
      else if (distance > -290 && distance <= -270 && DemRed == 5){dichuyen ( LOW  , LOW  , HIGH, HIGH, 15, 15, 15, 15);} 
      else if (distance > -270 && distance <= -259 && DemRed == 5){dichuyen ( LOW  , LOW  , HIGH, HIGH, 10, 10, 10, 10);}  
      else if (distance > -259 && DemRed == 5)                    {dichuyen ( LOW  , LOW  , HIGH, HIGH, 2, 2, 2,  2);delay(50);}//327,338
 //nhấn lần 6 di chuyen 
     /* if      (distance <= -450 )                                {dichuyen ( HIGH , HIGH , LOW  , LOW, 20, 15, 20, 15);}
      else if (distance < -345 && distance <= -330 && DemRed ==6) {dichuyen ( HIGH , HIGH , LOW  , LOW ,35,26,35,26);}
      else if (distance > -330 && distance <= -320&& DemRed ==6) {dichuyen ( HIGH  ,HIGH  ,LOW  , LOW, 25, 15, 25, 15);} 
      else if (distance > -320 && distance <= -310 && DemRed ==6){dichuyen ( HIGH  ,HIGH  ,LOW , LOW, 15, 15, 15, 15);} 
      else if (distance > -300 && distance <= -290 && DemRed ==6){dichuyen ( HIGH  , HIGH  , LOW , LOW, 10, 10, 10, 10);}  
      else if (distance > -290 && DemRed ==6)                    {dichuyen ( HIGH , HIGH  , LOW , LOW, 2, 2, 2,  2);delay(50);}//327,338
      if (red == LOW && !pink && !blue && !green) {
        dichuyen(HIGH, LOW, LOW, HIGH, 2, 2, 2, 2);
      break;
      }*/
    }
  }
}

