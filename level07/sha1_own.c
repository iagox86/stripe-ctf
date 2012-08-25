#include <stdio.h>
#include <openssl/sha.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  SHA_CTX c;
  unsigned char buffer[200];
  int i;
  char block1[] = "ivtAUQRQ6dFmH9user_id=5&count=1&lat=90&user_id=5&long=49&waffle=";
  char block2[] = "liege\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x28";

  char block3[] = "XXXXXXXXXXXXXXuser_id=5&count=1&lat=90&user_id=5&long=49&waffle=";
  char block4[] = "liege\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x28";
/*
user_id=5&count=1&lat=90&user_id=5&long=49&waffle=liege%80%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%02%28|sig:a37f1fce8fddfdd0bf76baba3c7cb699d6b19bc5

*/

  printf("Length1 = %d\n", (int)sizeof(block1) - 1);
  printf("Length2 = %d\n", (int)sizeof(block2) - 1);

  printf("Length3 = %d\n", (int)sizeof(block3) - 1);
  printf("Length4 = %d\n", (int)sizeof(block4) - 1);

  SHA1_Init(&c);
  SHA1_Update(&c, block1, 64);
  SHA1_Update(&c, block2, 64);
  SHA1_Update(&c, "&waffle=liege", 13);
  SHA1_Final(buffer, &c);

  for(i = 0; i < 20; i++)
    printf("%02x", buffer[i]);
  printf("\n"); 


  SHA1_Init(&c);
  SHA1_Update(&c, "XXXXXXXXXXXXXXuser_id=5&count=1&lat=90&user_id=5&long=49&waffle=", 64);
  SHA1_Update(&c, "liege\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x28", 64);
  c.h0 = 0x4c21a2ff;
  c.h1 = 0x8e0ea98f;
  c.h2 = 0x57e4215f;
  c.h3 = 0x43aa330a;
  c.h4 = 0x4873b683;

  SHA1_Update(&c, "&waffle=liege", 13);
  SHA1_Final(buffer, &c);

  for(i = 0; i < 20; i++)
    printf("%02x", buffer[i]);
  printf("\n");

/*  char attack1[] = "XXXXXXXXXXXXXXcount=2&lat=37.351&user_id=1&long=-119.827&waffle=";
  char attack2[] = "chicken\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x38";

  printf("Length1 = %d\n", (int)sizeof(attack1) - 1);
  printf("Length2 = %d\n", (int)sizeof(attack2) - 1);

  SHA1_Init(&c);
  SHA1_Update(&c, attack1, 64);
  SHA1_Update(&c, attack2, 64);

  c.h0 = 0xe8c57bb7;
  c.h1 = 0xcbb6fa98;
  c.h2 = 0xd116ed06;
  c.h3 = 0x622d6000;
  c.h4 = 0xee431d49;

  SHA1_Update(&c, "&waffle=liege", 13);
  SHA1_Final(buffer, &c);

  for(i = 0; i < 20; i++)
    printf("%02x", buffer[i]);
  printf("\n"); */

  return 0;
}
