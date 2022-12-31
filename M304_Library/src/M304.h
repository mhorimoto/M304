#ifndef _M304_H_
#define _M304_H_

#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet2.h>
#include <EEPROM.h>
#include <AT24CX.h>
#include <Wire.h>
#include <DS1307RTC.h>

/*** COMMON ***/

#define TRUE   1
#define FALSE  0

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

#ifndef _KYBDMEM_
#define _KYBDMEM_
struct KYBDMEM {
  uint8_t   kpos;
  uint16_t  selpos;
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
