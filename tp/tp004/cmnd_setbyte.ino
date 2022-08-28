#include <M304.h>

void cmnd_setbyte(String p,int at) {
  unsigned int addr,ofs1,ofs2;
  String q;
  byte d,v,buf[10];
  ofs1 = p.indexOf(" ");
  ofs2 = p.indexOf(" ",ofs1+1);
  if (ofs1>0) {  // アドレス引数がある
    q = p.substring(ofs1,ofs2);
    Serial.print("q=");
    Serial.println(q);
    Serial.print("ofs1=");
    Serial.println(ofs1);
    Serial.print("ofs2=");
    Serial.println(ofs2);
    q.toCharArray(&buf[0],7);
    addr = (unsigned int)strtol(buf,NULL,16);
    Serial.print("Addr=");
    Serial.println(addr,HEX);

    if (at==-1) { // EEPROM with CPU
      if (addr >= EEPROM.length()) {
        sprintf(lbf,"EEPROM Address %04XH is Overflow.\n",addr);
        Serial.print(lbf);
        return;
      }
    } else {
      if (addr > 0x7fff) {
        sprintf(lbf,"AT24C256 Address %04XH is Overflow.\n",addr);
        Serial.print(lbf);
        return;
      }
    }
    if (ofs2>0) { // データ引数がある
      q = p.substring(ofs2);
      q.toCharArray(&buf[0],4);
      d = (int)strtol(buf,NULL,16);
      sprintf(lbf,"[%04XH]<=%02XH",addr,d);
      Serial.println(lbf);
      return;
      if (at==-1) {
        v = EEPROM.read(addr);
        if (v!=d) {
          EEPROM.write(addr,d);
          Serial.println("DONE");
        } else {
          Serial.println("NO WRITE,SAME DATA");
        }
      } else { // AT24CX
        v = atmem.read(addr);
        if (v!=d) {
          atmem.write(addr,d);
          Serial.println("DONE");
        } else {
         Serial.println("NO WRITE,SAME DATA");
        }
      }
    } else {
      Serial.println(F("ERROR NO DATA"));
    }
  } else {
    Serial.println(F("ERROR NO ADDR"));
  }
}
