//reset các biến bằng select 
void reset(int nutReset)
{
  if(nutReset && DemSelect > 0){ 
    DemHT4 = 0 ;
    DemL1  = 0 ;
    DemRed = 0 ;
  }
}
//tong hop cac bien dem***************************
void Dogocban(){
  dogoc = analogRead(A13);
  goc = map(dogoc,0,1023,0,8000 );
  lcd.setCursor(16, 0);
  lcd.print(goc);
  // display.showNumberDec(goc,false,4,0);
  /*display.showNumberDecEx(goc,0b01000000);//dấu 2  chấm */
}
//*************************************************
void NangtheoEeprom(){
  if(blue && DemBlue == 1){
    digitalWrite(A1,LOW);
    digitalWrite(A0,HIGH);
    xung=xungType1;
  }
  if (goc>gocType1 && DemBlue ==1){
    digitalWrite(A1,LOW);
    digitalWrite(A0,LOW);
  }
  if(blue && DemBlue == 2){
    digitalWrite(A0,LOW);
    digitalWrite(A1,HIGH);
    xung=xungType2;
  }
  if (goc>gocType2 && DemBlue ==2){
    digitalWrite(A1,LOW);
    digitalWrite(A0,LOW);
  }
}
//***********************************************
void(* resetFunc) (void) = 0;//cài đặt hàm reset
void Resetboard(int b ){
  if(b){
    resetFunc();//tiến hành reset
  }
}
//**********************************************
//dungkhancapdc
void Nutdungdc(int nut){
  GoiLaiBien();
  if(nut){
    analogWrite(PWM8,pwm(0));
  }
}
//**********************************************
//chinhlaikepvong
void Chinhlaikepvong(int y , int x )
{  GoiLaiBien();
  if(y == -1023 && x == 4){
    digitalWrite(DIR5, LOW);  
    analogWrite(PWM5, pwm(60));
    digitalWrite(DIR7, LOW);  
    analogWrite(PWM7, pwm(60));
    Serial.println("nang len");
  }
  if(y == 1023 && x == 4){
    digitalWrite(DIR5, HIGH);  
    analogWrite(PWM5, pwm(60));
    digitalWrite(DIR7, HIGH);  
    analogWrite(PWM7, pwm(60));
    Serial.println("ha xuong");
  }
  if(y == -5 && x == 4){
    analogWrite(PWM5,pwm(0));
    analogWrite(PWM7,pwm(0));
    Serial.println("stop");
  }
}


/*khử nhiễu nút nhấn 
if(button){
  delay(50);
  if(button){
    dem++; //code trong nay
    }while(button);
  }
*/   

/*//ví dụ về lưu giá trị 
#include <EEPROM.h>
void setup() {
  Serial.begin(9600);
}
int diaChi=0;
void loop() {
  int giaTri = EEPROM.read(diaChi);
  EEPROM.write(diaChi, 5);
  Serial.println(giaTri);
}
*/


