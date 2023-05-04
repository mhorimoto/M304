#define _M304_CPP_
#include <M304.h>

extern char *pgname;
LiquidCrystal lcd(RS,RW,ENA,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7);
AT24C256      atmem(0);
EthernetClient client;

stM304 st_m;

void m304Init(void) {
  int i;
  Ethernet.init(53);
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
  lcd.begin(20,4);
  lcd.print(pgname);
  for ( i=0;i<6;i++ ) {
    st_m.mac[i] = atmem.read(LC_MAC+i);
  }
}

/*********************************/
/* Cross Key Switch sub-routine  */
/*********************************/
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

void debug_print(void) {
  char lbf[80];
  int i;
  sprintf(lbf,"MAC:%02X%02X.%02X%02X.%02X%02X",st_m.mac[0],st_m.mac[1],st_m.mac[2],st_m.mac[3],st_m.mac[4],st_m.mac[5]);
  Serial.println(lbf);
  Serial.print("IP:");
  Serial.println(st_m.ip);
  Serial.print("GW:");
  Serial.println(st_m.gw);
  Serial.print("DNS:");
  Serial.println(st_m.dns);
}

void LCDd::initWriteArea(int p) {
  int x,y;
  if (p >= PAGECNT) return;
  for(y=0;y<4;y++) {
    for(x=0;x<20;x++) {
      LCDd::tarea[p][x][y] = ' ';
    }
  }
}

void LCDd::LineWrite(int p,int y) {
  int x;
  if (y>3) return; 
  if (p >= PAGECNT) return;
  LCDd::setCursor(0,y);
  for(x=0;x<20;x++) {
    LCDd::print(LCDd::tarea[p][x][y]);
  }
}

void LCDd::PageWrite(int p) {
  int y;
  if (p >= PAGECNT) return;
  for (y=0;y<4;y++) {
    LCDd::LineWrite(p,y);
  }
}

void LCDd::CharWrite(int p,int x,int y,char a) {
  if (p >= PAGECNT) return;
  if (LCDd::setWriteChar(p,x,y,a)) {
    LCDd::setCursor(x,y);
    LCDd::print(a);
  }
}
  
int LCDd::setWriteChar(int p,int x,int y,char a) {
  if (p >= PAGECNT) return;
  if ((x<20)&&(y<4)) {
    LCDd::tarea[p][x][y] = a;
    return 1;
  }
  return 0;
}

void LCDd::IntWrite(int p,int x,int y,int w,bool zp,int a) {
  int i;
  char sv[6],fmt[5];
  Serial.begin(115200);
  if ((w < 1) || (w > 5)) {
    Serial.println("w out of range");
    Serial.end();
    return;
  }
  if (p >= PAGECNT) return;
  if (zp) {
    snprintf(fmt,5,"%%0%dd",w);
  } else {
    snprintf(fmt,4,"%%%dd",w);
  }
  Serial.end();
  snprintf(sv,w+1,fmt,a);
  if (LCDd::setWriteChar(p,x,y,a)) {
    LCDd::setCursor(x,y);
    LCDd::print(sv);
  }
  LCDd::setCursor(x,y);
}

int LCDd::getDataInt(int p,int x,int y,int w) {
  int i,v;
  char s[6];
  if ((w>5)||(w<1))  return 0;
  for(i=0;i<w;i++) {
    s[i] = LCDd::tarea[p][x+i][y];
  }
  s[i]=(char)0;
  v = int(s);
}

#undef _M304_CPP_
