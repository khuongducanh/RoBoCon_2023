#include "Arduino.h"

  //Gọi OUTPUT các chân di chuyển
  pinMode(DIR1, OUTPUT); pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT); pinMode(PWM2, OUTPUT);
  pinMode(DIR3, OUTPUT); pinMode(PWM3, OUTPUT); 
  pinMode(DIR4, OUTPUT); pinMode(PWM4, OUTPUT); 
  pinMode(DIR5, OUTPUT); pinMode(PWM5, OUTPUT);
  pinMode(DIR6, OUTPUT); pinMode(PWM6, OUTPUT); 
  pinMode(DIR7,OUTPUT);  pinMode(PWM7,OUTPUT );
  pinMode(DIR8, OUTPUT); pinMode(PWM8, OUTPUT);
  //Gọi OUTPUT các chân relay
  pinMode(xilanhkepvong   ,OUTPUT); 
  pinMode(xilanhnangcocau ,OUTPUT);digitalWrite(xilanhnangcocau,LOW);
  pinMode(xilanhnapvong   ,OUTPUT); 
  pinMode(xilanhkep       ,OUTPUT);digitalWrite(xilanhkep,HIGH); 
  pinMode(RELAY11,OUTPUT);
  pinMode(RELAY12,OUTPUT); 
  // pinMode(RELAY10,OUTPUT);
  // pinMode(RELAY9,OUTPUT);

  digitalWrite(xilanhkepvong, LOW);
  digitalWrite(xilanhnangcocau, LOW);
  digitalWrite(xilanhnapvong, LOW);
  digitalWrite(xilanhkep, LOW);
  digitalWrite(RELAY11, LOW);
  digitalWrite(RELAY12, LOW);
  //Cac cong tac hanh trinh
  pinMode(HT1,INPUT_PULLUP); pinMode(HT4,INPUT_PULLUP);
  pinMode(HT2,INPUT_PULLUP); pinMode(HT5,INPUT_PULLUP);
  pinMode(HT3,INPUT_PULLUP); pinMode(HT6,INPUT_PULLUP);
  //Dong co ban 
  //analogWrite(PWM6, 0);
  //Cho 7 dong co Stop
  analogWrite (PWM1, 255);
  analogWrite (PWM2, 255);
  analogWrite (PWM3, 255);
  analogWrite (PWM4, 255);
  analogWrite (PWM5, 255);
  analogWrite (PWM6, 255);
  analogWrite (PWM7, 255);
  analogWrite (PWM8, 255);
  //Nut nhan tren LCD
  pinMode(37,INPUT_PULLUP);
  pinMode(35,INPUT_PULLUP);
  //Encoder
  pinMode(21,INPUT_PULLUP);pinMode(20, INPUT_PULLUP);   //encode 1
  pinMode(18,INPUT_PULLUP);pinMode(19, INPUT_PULLUP);   //encode 2
  //ngat attachinterrupt
  attachInterrupt(2, ai1, RISING);
  attachInterrupt(3, ai0, RISING);
  attachInterrupt(4, bi0, RISING);
  attachInterrupt(5, bi1, RISING); 
  //xilanh dien
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  //cam bien vat can
  pinMode(A8, INPUT_PULLUP);
  pinMode(A9, INPUT_PULLUP);
  //Do goc ban bang bien tro 
  pinMode(A13,INPUT_PULLUP);
  //sensor xilanh
  pinMode(A10,INPUT_PULLUP);//ngang
  pinMode(A11,INPUT_PULLUP);//duoi
  pinMode(A12,INPUT_PULLUP);//tren

