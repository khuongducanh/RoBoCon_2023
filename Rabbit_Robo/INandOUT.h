//Gọi OUTPUT các chân di chuyển
  pinMode(DIR1, OUTPUT); pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT); pinMode(PWM2, OUTPUT);
  pinMode(DIR3, OUTPUT); pinMode(PWM3, OUTPUT); 
  pinMode(DIR4, OUTPUT); pinMode(PWM4, OUTPUT); 
  pinMode(DIR5, OUTPUT); pinMode(PWM5, OUTPUT);
  pinMode(DIR6, OUTPUT); pinMode(PWM6, OUTPUT); 
  pinMode(DIR7,OUTPUT);  pinMode(PWM7, OUTPUT );
  pinMode(DIR8, OUTPUT); pinMode(PWM8, OUTPUT);
  //Gọi OUTPUT các chân relay 2
  pinMode(xilanhnapvong,OUTPUT); //RELAY7
  pinMode(RELAY8,OUTPUT); //RELAY8 
  pinMode(RELAY9,OUTPUT);
  pinMode(RELAY10,OUTPUT);
  pinMode(RELAY11,OUTPUT);
  pinMode(RELAY12,OUTPUT); 
  //Cac cong tac hanh trinh
  pinMode(HT1,INPUT_PULLUP);
  pinMode(HT2,INPUT_PULLUP);
  pinMode(HT3,INPUT_PULLUP);
  pinMode(HT4,INPUT_PULLUP);
  pinMode(HT5,INPUT_PULLUP);
  pinMode(HT6,INPUT_PULLUP);
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
  //tiemcan
  pinMode(A0,INPUT_PULLUP);//tiemcan1
  pinMode(A1,INPUT_PULLUP);//tiemcan2
  //goc
  pinMode(A2,INPUT_PULLUP);//dogocban
//************Quét tay ps2************************// 
   error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_CS, PS2_DAT, pressures, rumble);
  type = ps2x.readType();
  switch (type) {//Ket noi PS2
    case 0:
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("KhongTimThay");
      lcd.setCursor(0, 1);
      lcd.print("Kiem Tra Tay Cam...");
      Serial.println("Disconnected");
      break;
    case 1:
      lcd.clear();  
      lcd.setCursor(0, 0);
      lcd.print("DaKetNoi..");
      Serial.println("Connected");
      break;
  }
//***********************end*****************************//  