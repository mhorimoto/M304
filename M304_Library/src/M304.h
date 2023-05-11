#ifndef _M304_H_
#define _M304_H_
#define _M304_H_V  105

#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet2.h>
#include <EEPROM.h>
#include <AT24CX.h>
#include <Wire.h>
#include <DS1307RTC.h>

/*** COMMON ***/

#define TRUE      1
#define FALSE     0
#define RUN       0
#define CMND1ST   1
#define CMND      2
#define UTIL1ST   3
#define UTIL      4

#define NETCONFIG 0
#define RTCCONFIG 1
#define SCHCONFIG 2

/*** Define for LCD ***/
#define RS        37
#define RW        38
#define ENA       39
#define DB0       40
#define DB1       41
#define DB2       42
#define DB3       43
#define DB4       44
#define DB5       45
#define DB6       46
#define DB7       47
#define PAGECNT    2

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

/*** Ethernet2 Ports ***/
#define NICSS    53

/*** I2C Address ***/
#define AT24LC254_ADDR   0x50
#define AT24LC254_INDEX  0

/*** EEPROM LOWCORE ASSIGN ***/
#define LC_UECS_ID  0
#define LC_MAC      6
#define LC_START    0x20
#define LC_END      0x7fff

typedef struct stM304 {
  byte mac[6];
  boolean dhcpflag=true;
  byte set_ip[4];
  IPAddress ip;
  IPAddress gw;
  IPAddress dns;
};

/*  Cross Key Switch */

#define K_ENT    1
#define K_UP     2
#define K_DOWN   4
#define K_LEFT   8
#define K_RIGHT 16

#define K_DIGIT  32
#define K_XDIGIT 33
#define K_PRINT  34
#define K_ALPHA  35
#define K_ALNUM  36

#define PUSH_SHORT 1000
#define PUSH_LONG  300000

#ifndef _KYBDMEM_
#define _KYBDMEM_
struct KYBDMEM {
  uint8_t   kpos;
  uint16_t  selpos;
  bool      longf;
};
#endif
#ifndef _M304_COMMON_KYBD
#endif

#ifndef _M304_COMMON_DISPLAY
#define _M304_COMMON_DISPLAY 1

class LCDd : public LiquidCrystal {
 private:
  char tarea[PAGECNT][20][4];
 public:
 LCDd():LiquidCrystal(RS,RW,ENA,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7) {
  LiquidCrystal:init(0, RS,RW,ENA,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7);
};
 LCDd(uint8_t rs, uint8_t enable,
      uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
      uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
  LiquidCrystal(rs,enable,d0,d1,d2,d3,d4,d5,d6,d7){
  LiquidCrystal:init(0, rs,255,enable,d0,d1,d2,d3,d4,d5,d6,d7);
};
  LCDd(uint8_t rs, uint8_t rw, uint8_t enable,
       uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
       uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
  LiquidCrystal(rs,rw,enable,d0,d1,d2,d3,d4,d5,d6,d7){};
  LCDd(uint8_t rs, uint8_t rw, uint8_t enable,
      uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
  LCDd(uint8_t rs, uint8_t enable,
      uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
  void initWriteArea(int);
  int  setWriteChar(int,int,int,char),getDataInt(int,int,int,int),setLine(int,int,char *);
  int  IntRead(int,int,int,int);
  char CharRead(int,int,int);
  void LineWrite(int,int),PageWrite(int),CharWrite(int,int,int,char),IntWrite(int,int,int,int,bool,int);
  void TextWrite(int,int,int,char[]),IPWrite(int,int,int,IPAddress);
};

#endif

#ifndef _M304_CPP_
    extern void m304Init(void);
    extern void debug_print(void);
  #endif
  extern stM304 st_m;
  extern LiquidCrystal lcd;
  extern AT24C256      atmem;
  extern EthernetClient client;
#endif
