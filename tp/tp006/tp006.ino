#include <M304.h>

char *pgname = "M304jp TP006 Ver0.01";

void setup(void) {
  char lbf[80];
  int  i;
  Serial.begin(115200);
  while(!Serial) {
    ;
  }
  for (i=0;i<6;i++) {
    mac[i] = atmem.read(LC_MAC+i);
  }
  m304Init();
  sprintf(lbf,"MAC:%02X%02X.%02X%02X.%02X%02X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
  lcd.setCursor(0,1);
  lcd.print("Connect Console USB");
  lcd.setCursor(0,2);
  lcd.print("Baud:115200");
  lcd.setCursor(0,3);
  Ethernet.begin(mac);
  if (Ethernet.begin(mac)==0) {
    Serial.println("Failed to configure Ethernet using DHCP.");
    lcd.print("FAIL DHCP PLS RESET");
  } else {
  }
}

void loop(void) {
}
