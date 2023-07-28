void dkdongco(){
//Tang xung ban
  int chayXung1=0;
  while(green && chayXung1<10 && !red ){
    chayXung1++;
    lcd.setCursor(4,2);
    lcd.print(xung);
    Goilaibien() ;
  }
  if(chayXung1>1&&chayXung1<10){
    analogWrite(PWM8,pwm(xung));
    xung++;
  }
  if(xung==254){
    xung=253; 
  }
  while(green && !red){
    Goilaibien() ;
    while(green && chayXung1==10){
      Goilaibien() ;
      xung++;
      analogWrite(PWM8,pwm(xung));
      lcd.setCursor(4,2);
      lcd.print(xung);
      if(xung==254){ xung=253;break;}
    }
  }

//giam xung ban
  int chayXung2=0;
  do{
    chayXung2++;
    Goilaibien() ;
  }while(blue&&chayXung2<5 && !red && !green);
  if(chayXung2 > 1){
    xung--;
    analogWrite(PWM8,pwm(xung));
    lcd.setCursor(4, 2); lcd.print("            ");
  }
  if(xung<0)
  xung=0;
  while(blue&&chayXung2 == 10 && !red && !green){
    xung--;
    analogWrite(PWM8,pwm(xung));
    lcd.setCursor(4,2) ; lcd.print(xung);

    Goilaibien() ;
    if(xung<0){xung=0;break;}
  }
  lcd.setCursor(4,2) ; lcd.print(xung);

}

