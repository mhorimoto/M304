#include <LiquidCrystal.h>

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

LiquidCrystal lcd(RS,RW,ENA,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7);

int tpn=0 ;

void setup(void) {
  lcd.begin(20,4);
  lcd.print("M304jp TEST Program");
}

void loop(void) {
  int t ;
  switch(tpn) {
  case 0:
    lcd.setCursor(0, 1);
    t = millis() / 1000;
    lcd.print(t);
    if (t>60) tpn++;
    break;
  case 1:
    lcd.setCursor(0,1);
    lcd.print("AutoScroll test");
    lcd.setCursor(0,2);
    for (int thisChar = 0; thisChar < 10; thisChar++) {
      lcd.print(thisChar);
      delay(500);
    }
    lcd.setCursor(20,3);
    lcd.autoscroll();
    for (int thisChar = 0; thisChar < 10; thisChar++) {
      lcd.print(thisChar);
      delay(500);
    }
    lcd.noAutoscroll();
    lcd.clear();
  }
}
