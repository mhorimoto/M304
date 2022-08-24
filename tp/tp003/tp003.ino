#include <LiquidCrystal.h>

/*** Define for LCD ***/
#define RS     37
#define RW     38
#define ENA    39
#define DB0    40
#define DB1    41
#define DB2    42
#define DB3    43
#define DB4    44
#define DB5    45
#define DB6    46
#define DB7    47

/*** Define for Arrow Key ***/
#define SW_SAFE    3
#define SW_RLY    31
#define SW_ENTER  32
#define SW_UP     33
#define SW_DOWN   34
#define SW_LEFT   35
#define SW_RIGHT  36
#define SELECT_VR A15

/*** Define Relay Ports ***/
#define  RLY1    22
#define  RLY2    23
#define  RLY3    24
#define  RLY4    25
#define  RLY5    26
#define  RLY6    27
#define  RLY7    28
#define  RLY8    29

LiquidCrystal lcd(RS,RW,ENA,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7);

void setup(void) {
  lcd.begin(20,4);
  lcd.print("M304jp TP003 Ver1.01");
  pinMode(SW_ENTER,INPUT_PULLUP);
  pinMode(SW_UP,INPUT_PULLUP);
  pinMode(SW_DOWN,INPUT_PULLUP);
  pinMode(SW_LEFT,INPUT_PULLUP);
  pinMode(SW_RIGHT,INPUT_PULLUP);
  pinMode(SW_SAFE,INPUT_PULLUP);
  pinMode(SW_RLY,INPUT);
  pinMode(SELECT_VR,INPUT);
  pinMode(RLY1,OUTPUT);
  digitalWrite(RLY1,HIGH);
  pinMode(RLY2,OUTPUT);
  digitalWrite(RLY2,HIGH);
  pinMode(RLY3,OUTPUT);
  digitalWrite(RLY3,HIGH);
  pinMode(RLY4,OUTPUT);
  digitalWrite(RLY4,HIGH);
  pinMode(RLY5,OUTPUT);
  digitalWrite(RLY5,HIGH);
  pinMode(RLY6,OUTPUT);
  digitalWrite(RLY6,HIGH);
  pinMode(RLY7,OUTPUT);
  digitalWrite(RLY7,HIGH);
  pinMode(RLY8,OUTPUT);
  digitalWrite(RLY8,HIGH);
  delay(1000);
  digitalWrite(RLY8,LOW);
  delay(1000);
  digitalWrite(RLY8,HIGH);
  lcd.setCursor(0,1);
  lcd.print("RLY MODE:");
  lcd.setCursor(12,2);
  lcd.print("87654321");
}

void loop(void) {
  int m,v;
  m = digitalRead(SW_RLY);
  lcd.setCursor(9,1);
  if ( m == LOW ) {
    lcd.print("MANUAL");
  } else {
    lcd.print("AUTO  ");
  }
  v = analogRead(SELECT_VR);
  v = map(v,0,1023,0,255);
  lcd.setCursor(0,2);
  lcd.print("VALUE:");
  lcd.print(v,16);
  for(int i=0;i<8;i++) {
    lcd.setCursor(19-i,3);
    if (bitRead(v,i)==0) {
      lcd.print("o");
      digitalWrite(22+i,HIGH);
    } else {
      lcd.print("C");
      digitalWrite(22+i,LOW);
    }
  }
}
