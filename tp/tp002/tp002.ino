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

LiquidCrystal lcd(RS,RW,ENA,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7);

void setup(void) {
  lcd.begin(20,4);
  lcd.print("M304jp TP002 Ver2.10");
  pinMode(SW_ENTER,INPUT_PULLUP);
  pinMode(SW_UP,INPUT_PULLUP);
  pinMode(SW_DOWN,INPUT_PULLUP);
  pinMode(SW_LEFT,INPUT_PULLUP);
  pinMode(SW_RIGHT,INPUT_PULLUP);
  pinMode(SW_SAFE,INPUT_PULLUP);
  pinMode(SW_RLY,INPUT);
  pinMode(SELECT_VR,INPUT);
  lcd.setCursor(8,1);
  lcd.print("SAFE:");
  lcd.setCursor(8,2);
  lcd.print(" RLY:");
  lcd.setCursor(8,3);
  lcd.print("SELE:");
}

void loop(void) {
  int e,u,d,l,r,s,o,a;
  e = digitalRead(SW_ENTER);
  u = digitalRead(SW_UP);
  d = digitalRead(SW_DOWN);
  l = digitalRead(SW_LEFT);
  r = digitalRead(SW_RIGHT);
  s = digitalRead(SW_SAFE);
  o = digitalRead(SW_RLY);
  a = analogRead(SELECT_VR);
  
  lcd.setCursor(3,2);
  if ( e == LOW ) {
    lcd.print("*");
  } else {
    lcd.print(" ");
  }
  lcd.setCursor(3,1);
  if ( u == LOW ) {
    lcd.print("^");
  } else {
    lcd.print(" ");
  }
  lcd.setCursor(3,3);
  if ( d == LOW ) {
    lcd.print("v");
  } else {
    lcd.print(" ");
  }
  lcd.setCursor(2,2);
  if ( l == LOW ) {
    lcd.print("<");
  } else {
    lcd.print(" ");
  }
  lcd.setCursor(4,2);
  if ( r == LOW ) {
    lcd.print(">");
  } else {
    lcd.print(" ");
  }
  lcd.setCursor(13,1);
  if ( s == LOW ) {
    lcd.print("ON ");
  } else {
    lcd.print("OFF");
  }
  lcd.setCursor(13,2);
  if ( o == LOW ) {
    lcd.print("MANUAL");
  } else {
    lcd.print("AUTO  ");
  }
  lcd.setCursor(13,3);
  lcd.print(a);
  if (a<10) {
    lcd.setCursor(14,3);
    lcd.print("   ");
  } else if (a<100) {
    lcd.setCursor(15,3);
    lcd.print("  ");
  } else if (a<1000) {
    lcd.setCursor(16,3);
    lcd.print(" ");
  }
}
