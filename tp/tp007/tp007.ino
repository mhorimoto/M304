#include <M304.h>
#include <TimeLib.h>

// GOOD: $GPRMC,215335.00,A,3335.49889,N,13022.91207,E,1.853,356.84,221122,,,A*63
// BAD:  $GPRMC,215341.00,V,,,,,,,221122,,,N*7D

#define GPS_STATUS  17
#define GPS_TIME    7
#define GPS_TODLEN  6
#define GPS_DATE    59

int tpn=0 ;
char *pgname = "M304jp TP007 Ver1.80";
byte lcdtxt[4][21];

struct GPS_DATA {
  int i_hour,i_minute,i_second;
  int i_year,i_month,i_day,i_wday;
  String st_hour,st_minute,st_second;
  String st_year,st_month,st_day;
} gps_data;

void setup(void) {
  String lb;
  int x,y;
  Serial.begin(115200);
  Serial3.begin(9600);
  m304Init();
  for(y=1;y<4;y++) {
    for(x=0;x<20;x++) {
      lcdtxt[y][x] = 0x20;
    }
    lcdtxt[y][x] = (byte)NULL;
  }
}

void loop(void) {
  String lb,t,t_h,t_m,t_s,d_y,d_m;
  int l_h; // Local time (+9);
  bool r;
  char *pt_lcd;
  
  if (Serial3.available()>0) {
    lb = Serial3.readStringUntil('\n');
    if (lb.startsWith("$GPRMC")) {
      r = decode_GPRMC(lb);
      pt_lcd = &lcdtxt[1][0];
      gps_data.st_year.toCharArray(&lcdtxt[1][0],5);
      Serial.print("/");
      Serial.println(pt_lcd);
      lcdtxt[1][4] = '/';
      gps_data.st_month.toCharArray(&lcdtxt[1][5],3);
      Serial.print(gps_data.st_month);
      Serial.print("/");
      lcdtxt[1][7] = '/';
      gps_data.st_day.toCharArray(&lcdtxt[1][8],3);
      lcdtxt[1][10] = ' ';
      gps_data.st_hour.toCharArray(&lcdtxt[1][11],3);
      lcdtxt[1][13] = ':';
      gps_data.st_minute.toCharArray(&lcdtxt[1][14],3);
      lcdtxt[1][16] = ':';
      gps_data.st_second.toCharArray(&lcdtxt[1][17],3);
      if (r) {
        lcdtxt[1][19] = 'A';
        Serial.println(" A");
      } else {
        lcdtxt[1][19] = 'V';
        Serial.println(" V");
      }
      lcd.setCursor(0, 1);
      lcd.print(pt_lcd);
      Serial.println(pt_lcd);
    }
  }
}

boolean decode_GPRMC(String lb) {
  int x,p0,p1;
  String t;
  //  Serial.println(lb);
  p1 = 18;
  for (x=0;x<6;x++) {
    p1 = lb.indexOf(",",p1+1);
  }
  p0 = p1+1;
  gps_data.i_day = lb.substring(p0,p0+2).toInt();
  gps_data.i_month = lb.substring(p0+2,p0+4).toInt();
  gps_data.i_year  = 2000 + lb.substring(p0+4,p0+6).toInt();

  t = lb.substring(GPS_TIME,GPS_TIME+GPS_TODLEN);
  setTime(t.substring(0,2).toInt(),t.substring(2,4).toInt(),t.substring(4,6).toInt(),gps_data.i_day,gps_data.i_month,gps_data.i_year);
  adjustTime(9 * SECS_PER_HOUR);
  gps_data.i_hour = hour();
  gps_data.st_hour = normalize_2col(gps_data.i_hour);
  gps_data.i_minute = minute();
  gps_data.st_minute = normalize_2col(gps_data.i_minute);
  gps_data.i_second = second();
  gps_data.st_second = normalize_2col(gps_data.i_second);
  gps_data.i_year = year();
  gps_data.st_year = String(gps_data.i_year);
  gps_data.i_month = month();
  gps_data.st_month = normalize_2col(gps_data.i_month);
  gps_data.i_day = day();
  gps_data.st_day = normalize_2col(gps_data.i_day);

  if (lb.charAt(GPS_STATUS)=='A') {
    return true;
  } else {
    return false;
  }
}

String normalize_2col(int i) {
  String a;
  a = String(i);
  if (i<10) {
    a = String("0")+a;
  }
  return(a);
}
