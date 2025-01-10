#define ROMBASE 0x10030000u

uint8_t *basicrom=(uint8_t *)(ROMBASE);             // SYSTEM 0x10030000
uint8_t *extrom1  =(uint8_t *)(ROMBASE+0x8000);     // FD     0x10038000
uint8_t *extrom2  =(uint8_t *)(ROMBASE+0xc000);     // SOUND  0x1003c000
uint8_t *cartrom1 =(uint8_t *)(ROMBASE+0x10000);    // CART1  0x10040000
uint8_t *cartrom2 =(uint8_t *)(ROMBASE+0x30000);    // CART2  0x10060000
