 void Hanhtrinh(){

   //reset lồng
   if(DemL1 == 0 && b1 == 1){
      digitalWrite(DIR5,LOW);
      analogWrite(PWM5,pwm(40));
   }
   else if(b1 == 0 && DemL1 == 0){
     analogWrite(PWM5,pwm(0));
   }

  //nâng lồng vòng 
   if(DemL1 == 1 && b1 == 0 && tiemcan1 == 1){
     digitalWrite(DIR5,HIGH);
     analogWrite(PWM5,pwm(40));
   }
   else if(tiemcan1 == 0 && b1 == 1 && DemL1 == 1){
     analogWrite(PWM5,pwm(0));
   }
   
  //hạ lồng vòng 
   if(DemL1 == 2 && b1 == 1){
     digitalWrite(DIR5,LOW);
     analogWrite(PWM5,pwm(40));
   }
   else if(b1 == 0 && DemL1 == 2){
     analogWrite(PWM5,pwm(0));
   }
 }




void Nangvong(int y , int x){
  if(y >= -1023 && y <-200 && x == 4){
    digitalWrite(DIR5,HIGH);
    analogWrite(PWM5,pwm(40));
    Serial.println("nag vong");
  }
  if(y <= 1023 && y > 200 && x == 4){
    digitalWrite(DIR5,LOW);
    analogWrite(PWM5,pwm(40));
    Serial.println("ha vog");
  }
  if(y == -5 && x == 4){
    analogWrite(PWM5,pwm(0));
    Serial.println("dung long");
  }
}


