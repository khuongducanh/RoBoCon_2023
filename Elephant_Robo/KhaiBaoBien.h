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
#define pressures false
#define rumble    false
//move
#define DIR1 13    //trên trái 
#define PWM1 12
#define DIR2 11    //trên phải
#define PWM2 10
#define DIR3 9     //dưới phải
#define PWM3 8
#define DIR4 7     //dưới trái
#define PWM4 6
#define DIR5 28    //động cơ lồng bên trái 
#define PWM5 5
#define DIR6 26    //động cơ gắp vòng đưa vào lồng 
#define PWM6 4 
#define DIR7 24    //động cơ lồng bên phải 
#define PWM7 3
    
#define DIR8 22   //xungdcban
#define PWM8 2 
//6 Chan Relay
#define xilanhkepvong    42 //2xilanh gapvong 
#define xilanhnangcocau  48 //2xilanh nangcocau 
#define xilanhnapvong    46 //1xilanh napvong 
#define xilanhkep        44 //1xilanh kepvong 
#define RELAY11 50 
#define RELAY12 52 
//button hành trình
#define HT1 23 
#define HT2 25 
#define HT3 27 
#define HT4 29 
#define HT5 31 
#define HT6 33 
int b1,b2,b3,b4,b5,b6;
int cambien1,cambien2 ;
//EEPROM
#define diaChigoc1  50
#define diaChigoc2  100
#define diaChixung1 150
#define diaChixung2 200
int xungType1, xungType2, gocType1, gocType2;
//led7doan4so
#define TX3 14
#define RX3 15
// TM1637Display display(TX3,RX3);
//Dao xung PWM
int pwm(int x) 
{return 255 - x;}

//xung dong co ban
int xung = 0 ;

//Encoder
const float pi = 3.14 ;
const float d =  9.6;
const int   n  = 800;
float distance = 000.000;
volatile long temp, counter = 0;
//gap vong va tu chay encoder
static int DemBlue=0;
static int DemGreen = 0 ;
static int DemRed = 0 ;
static int DemSelect = 0 ;
bool DCBAN = false;
bool vovong = true ;
int DemPink=0;
int DemUp=0;
int DemDown=0;
int DemLeft=0;
int DemRight=0;
int DemL1=0;
int DemL2=0;
int DemR1=0;
int DemR2=0;
int DemEEPROM=0;
int DemHT1 = 0;
int DemHT2 = 0;
int DemHT4 = 0 ;
int DemHT5 = 0 ;
//đo góc
unsigned int goc,dogoc;
//kiểm tra trạng thái nut nhan
 int preL1R3=0;
 int sensorA11,sensorA12,sensorA10;