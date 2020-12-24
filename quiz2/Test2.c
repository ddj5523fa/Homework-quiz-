#include <stdint.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)


uint64_t hexchar2val(char* input)
{
  uint64_t res = 0,pos = 0;
  if (*(input+0) == '0' && *(input + 1) == 'x') //需要過濾掉0x否則會出錯
        pos = 2;
  for (int i = 0+pos; i < strlen(input); i++) {
    uint64_t letter = input[i] & 0x40;
    uint64_t shift = (letter >> 3) | (letter >> 6);
    res = (res << 4 | ((input[i] + shift) & 0xf));
  }
  return res;
}

void main()
{
  printf("%ld\n", hexchar2val("0xFF"));
  printf("--------------------------------\n");
  printf("%ld\n", hexchar2val("0xFFF"));
  printf("%lld\n", hexchar2val("0xCAFEBABE"));
  printf("%lld\n", hexchar2val("0x8BADFOOD"));
}
