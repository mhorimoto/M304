#include <M304.h>
#include "crosskey.h"

struct KYBDMEM crosskey,*ptr_crosskey;

struct KYBDMEM *getCrossKey(void) {
  int e,u,d,l,r,a;
  e = digitalRead(SW_ENTER);
  u = digitalRead(SW_UP);
  d = digitalRead(SW_DOWN);
  l = digitalRead(SW_LEFT);
  r = digitalRead(SW_RIGHT);
  a = analogRead(SELECT_VR);
  crosskey.kpos = 0;
  if (e==LOW) crosskey.kpos |= K_ENT;
  if (u==LOW) crosskey.kpos |= K_UP;
  if (d==LOW) crosskey.kpos |= K_DOWN;
  if (l==LOW) crosskey.kpos |= K_LEFT;
  if (r==LOW) crosskey.kpos |= K_RIGHT;
  crosskey.selpos = a;
  ptr_crosskey = &crosskey;
  return(ptr_crosskey);
}

