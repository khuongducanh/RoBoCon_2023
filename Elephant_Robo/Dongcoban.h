void dkdongco(){
//Tang xung ban
  int chayXung1=0;
  while(green && chayXung1<10 && !red ){
    chayXung1++;
    lcd.setCursor(0,2);
    lcd.print(xung);
    GoiLaiBien() ;
  }
  if(chayXung1>1&&chayXung1<10){
    analogWrite(PWM8,pwm(xung));
    xung++;
  }
  if(xung==254){
    xung=253; 
  }
  while(green && !red){
    GoiLaiBien() ;
    while(green && chayXung1==10){
      GoiLaiBien() ;
      xung++;
      analogWrite(PWM8,pwm(xung));
      lcd.setCursor(0,2);
      lcd.print(xung);
      if(xung==254){ xung=253;break;}
    }
  }

//giam xung ban
  int chayXung2=0;
  do{
    chayXung2++;
    GoiLaiBien() ;
  }while(blue&&chayXung2<10 && !red && !green);
  if(chayXung2 > 1){
    xung--;
    analogWrite(PWM8,pwm(xung));
    lcd.setCursor(0, 2); lcd.print("            ");
  }
  if(xung<0)
  xung=0;
  while(blue&&chayXung2==10 && !red && !green){
    xung--;
    analogWrite(PWM8,pwm(xung));
    lcd.setCursor(0,2) ; lcd.print(xung);
    lcd.setCursor(0, 2); lcd.print("            ");
    GoiLaiBien() ;
    if(xung<0){xung=0;break;}
  }
  Serial.println(xung);
  lcd.setCursor(0,2) ; lcd.print(xung);

}
