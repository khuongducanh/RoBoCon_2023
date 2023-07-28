void inralcd(char Hienthi[100]){
//Serial.println(Hienthi);
 lcd.setCursor(0, 1);
 lcd.print(Hienthi);
  for(int i =0 ; i <= 3;i++){
    lcd.setCursor(10,i);
    lcd.print("|");
  }
  lcd.setCursor(0,2);
  lcd.print("Pwm:");

  lcd.setCursor(0,3);
  lcd.print("Goc:");

  //in ra lcd cong tac hanh trinh
  lcd.setCursor(11,0);
  lcd.print("CT:000000");

   //in ra lcd tiem can
  lcd.setCursor(11,1);
  lcd.print("TC:00");
}
