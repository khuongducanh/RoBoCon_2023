  void ShowLCD(char HienThi[50]){
    Serial.println(HienThi);
  lcd.setCursor(0, 1);
  lcd.print(HienThi);
  for(int i = 0 ; i < 4 ; i++){
    lcd.setCursor(11,i);
    lcd.print("|");
  }
}