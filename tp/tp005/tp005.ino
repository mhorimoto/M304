#include "M304.h"
EthernetClient client;

byte mac[] = { 0x02,0xA2,0x73,0x0B,0xFF,0xEE };
byte ip[] = { 192,168,0,177 };
void setup(void) {
  lcd.begin(20,4);
  lcd.print("M304jp TP005 Ver1.10");
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
  lcd.setCursor(0,1);
  lcd.print("Connect Console USB");
  lcd.setCursor(0,2);
  lcd.print("Baud:115200");
  Serial.begin(115200);
  while(!Serial) {
    ;
  }
  lcd.setCursor(0,3);
  Ethernet.init(53);
  Ethernet.begin(mac);
  if (Ethernet.begin(mac)==0) {
    Serial.println("Failed to configure Ethernet using DHCP.");
    lcd.print("FAIL DHCP PLS RESET");
  } else {
    lcd.print("IP:");
    Serial.print("IP:");
    for (byte tb=0; tb<4; tb++) {
      lcd.print(Ethernet.localIP()[tb],DEC);
      lcd.print(".");
      Serial.print(Ethernet.localIP()[tb],DEC);
      if (tb<3) {
        Serial.print(".");
      }
    }
    Serial.println();
  }
}

void loop(void) {
}
