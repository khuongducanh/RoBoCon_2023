
void Read_Write_EEPROM(int cot1,int cot2){
  if(R1 && L3 && cot1){
      AVR_EEPROM.write_2_byte(diaChigoc1, goc);
      AVR_EEPROM.write_2_byte(diaChixung1, xung);
      delay(10);
    }
  //
  if(R1 && L3 && cot2){
    AVR_EEPROM.write_2_byte(diaChigoc2, goc);
    AVR_EEPROM.write_2_byte(diaChixung2, xung);
    Serial.println("doc lan 2");
    delay(10);
  }
  if(R1 && R3){
    gocType1  = AVR_EEPROM.read_2_byte(diaChigoc1);
    xungType1 = AVR_EEPROM.read_2_byte(diaChixung1);
    gocType2  = AVR_EEPROM.read_2_byte(diaChigoc2);
    xungType2 = AVR_EEPROM.read_2_byte(diaChixung2);
    Serial.println("doc lan 3");
    // Goctype3 = AVR_EEPROM.read_2_byte(diaChi3);
  }
  //Chỉnh góc và xung cột 1
  if(cot1 && !R1 && !L3 ){
    digitalWrite(A1,LOW);
    digitalWrite(A0,HIGH);
    xung=xungType1;
  }
  //Chỉnh góc và xung cột 2
  if(cot2 && !R1 && !L3 ){
    digitalWrite(A1,LOW);
    digitalWrite(A0,HIGH);
    xung=xungType2;
  }
  analogWrite(PWM8,pwm(xung));
}
// Serial.print("goc ban = ");
//           Serial.println(goc);

//dừng lại khi đến đúng góc
void gocEEPROM(int stop){
  if (goc>gocType1){
    digitalWrite(A0,stop);
    digitalWrite(A1,stop);
  }
  if (goc>gocType2){
    digitalWrite(A0,stop);
    digitalWrite(A1,stop);
  }
  Dogocban();           //Đo góc bắn

}

// int curStateButton = digitalRead(button);//lấy trạng thái hiện tại của button
//   if (curStateButton==HIGH && preStateButton==LOW){
//     count++;
//   }
//   preStateButton=curStateButton;
//   Serial.println(count);



  