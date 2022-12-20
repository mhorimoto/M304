#include <M304.h>
#include "crosskey.h"

//struct KYBDMEM {
//  uint8_t   kpos;
//  uint16_t  selpos;
//} ;

char *pgname = "M304jp TP008 Ver1.02";

void setup(void) {
  m304Init();
}

void loop(void) {
  struct KYBDMEM *ptr_ck;

  char lcdtxt[21],*ptr_lcdtxt;
  extern struct KYBDMEM *getCrossKey(void);
  ptr_lcdtxt = &lcdtxt[0];
  ptr_ck = getCrossKey();
  sprintf(lcdtxt,"KEY: %02X  ",ptr_ck->kpos);
  lcd.setCursor(0,1);
  lcd.print(ptr_lcdtxt);
  sprintf(lcdtxt,"VOL: %03X  ",ptr_ck->selpos);
  lcd.setCursor(0,2);
  lcd.print(ptr_lcdtxt);
}

