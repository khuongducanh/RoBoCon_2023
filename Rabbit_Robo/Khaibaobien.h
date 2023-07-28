//lcd
const int rs = 43, en = 45, d4 = 47, d5 = 49, d6 = 51, d7 = 53;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//ps2
PS2X ps2x;  // create PS2 Controller Class
int up, down, right,left, L1, L2, L3, R1, R2, R3, pink, red,green,blue,traidoc,traingang,phaidoc, phaingang,start,select;
int error    = 0;
byte type    = 0;
byte vibrate = 0;
//PS2
#define PS2_DAT 30 
#define PS2_CMD 32  
#define PS2_CS  34  
#define PS2_CLK 36  
#define pressures true
#define rumble    true
//move
#define DIR1 13    //tren trai
#define PWM1 12
#define DIR2 11    //tren phải
#define PWM2 10
#define DIR3 9    //duoi phai      
#define PWM3 8
#define DIR4 7    //duoi trai
#define PWM4 6
#define DIR5 28   //dong co nang vong  
#define PWM5 5
#define DIR6 26   //dongcomoc
#define PWM6 4 
#define DIR7 24   //XILANHdien    
#define PWM7 3
#define DIR8 22   //dc bắn 
#define PWM8 2 
//6 Chan Relay
#define xilanhnapvong  42   //xianhnapvong
#define RELAY8  44  
#define RELAY9  46 
#define RELAY10 48
#define RELAY11 50 
#define RELAY12 52 
//button hành trình
#define HT1 23 //b1
#define HT2 25 //b2
#define HT3 27 //b3
#define HT4 29 //b4
#define HT5 31 //b5 
#define HT6 33 //b6
int b1,b2,b3,b4,b5,b6;
//Dao xung PWM
int pwm(int x) 
{return 255 - x;}
//bientiemcan
int tiemcan1,tiemcan2;
//xungdcban
int xung  = 0;
//nut lcd
int nutlcd1,nutlcd2;
//bien dem
int DemL1 = 0 ;
int DemSelect = 0;