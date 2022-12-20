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
