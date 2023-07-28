void dichuyen(int d1 ,int d2 ,int d3,int d4, int xungA,int xungB,int xungC,int xungD){
  digitalWrite(DIR1,d1);analogWrite(PWM1,pwm(xungA));
  digitalWrite(DIR2,d2);analogWrite(PWM2,pwm(xungB));
  digitalWrite(DIR3,d3);analogWrite(PWM3,pwm(xungC));
  digitalWrite(DIR4,d4);analogWrite(PWM4,pwm(xungD));
}
void tien  (int x){if(traidoc   >= -1023 && traidoc <-200   && traingang == 4 && !L1 && !R1) {inralcd("Tien  ");dichuyen(HIGH,LOW,LOW,HIGH,x,x,x,x);}}
void lui   (int x){if(traidoc   <=  1023 && traidoc > 200   && traingang == 4 && !L1 && !R1) {inralcd("Lui   ") ;dichuyen(LOW,HIGH,HIGH,LOW,x,x,x,x);}}
void trai  (int x){if(traingang >= -1023 && traingang <-200 && traidoc == -5  && !L1 && !R1)  {inralcd("Trai ");dichuyen(LOW,LOW,HIGH,HIGH ,x,x,x,x);}}
void phai  (int x){if(traingang <=  1023 && traingang > 200 && traidoc == -5  && !L1 && !R1)  {inralcd("Phai ");dichuyen(HIGH,HIGH,LOW,LOW,x,x,x,x);}}
void cheor (int x){if(traingang ==  1023 && traidoc<-30 && traidoc>-950 && !L1 && !R1){inralcd("CPhai");dichuyen(HIGH,LOW ,LOW, HIGH,x,0,x,0);}}
void cheol (int x){if(traingang == -1023 && traidoc<-30 && traidoc>-950 && !L1 && !R1){inralcd("CTrai");dichuyen(HIGH,LOW ,LOW, HIGH,0,x,0,x);}}
void cheodl(int x){if(traingang == -1023 && traidoc>30  && traidoc< 950 && !L1 && !R1){inralcd("TraiD");dichuyen(LOW,LOW ,HIGH, HIGH,x,0,x,0);}}
void cheodr(int x){if(traingang ==  1023 && traidoc>30  && traidoc< 950 && !L1 && !R1) {inralcd("PhaiD");dichuyen(LOW,HIGH,HIGH, LOW ,0,x,0,x);}}
void xoayl(int x){if(L1 && !R1 && traingang == 4 && traidoc == -5)                    {inralcd("xtrai");dichuyen(LOW ,LOW ,LOW ,LOW  ,x,x,x,x);}}
void xoayr(int x){if(R1 && !L1 && traingang == 4 && traidoc == -5)                    {inralcd("xphai");dichuyen(HIGH,HIGH,HIGH,HIGH ,x,x,x,x);}}
void dung()      {if(traingang > 0 && traingang < 10 && traidoc > -10 && traidoc < 0  && !L1 && !R1)              {inralcd("Stop"); dichuyen(HIGH,HIGH ,HIGH,HIGH,0,0,0,0);}}

void Speed(){
  int max = 25;
  tien  (max); lui (max);
  trai  (max); phai(max);
  cheor (max);cheol(max);
  cheodl(max);cheodr(max);
  dung();
}

void Move(){
  int binhthuong = 15;
  int liti       = 9 ;
  tien(binhthuong)  ;lui(binhthuong);
  trai(binhthuong)  ;phai(binhthuong);
  cheor(binhthuong) ;cheol(binhthuong);
  cheodl(binhthuong);cheodr(binhthuong);
  xoayl(liti);xoayr(liti);
  dung();
}