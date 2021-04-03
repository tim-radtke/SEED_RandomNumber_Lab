#include <stdio.h>
#include <stdlib.h>

#define LEN 16
#define LEN2 32

int main()
{
   int i;

   // 128 bits
   unsigned char * key = (unsigned char * ) malloc(sizeof(unsigned char) * LEN);
   FILE * random = fopen("/dev/urandom", "r");
   fread(key, sizeof(unsigned char) * LEN, 1, random);
   fclose(random);
   for (i = 0; i < LEN; i += 1)
   {
      printf("%.2x", (unsigned char)key[i]);
   }
   printf("\n");

   // 256 bits
   unsigned char * key = (unsigned char * ) malloc(sizeof(unsigned char) * LEN2);
   FILE * random = fopen("/dev/urandom", "r");
   fread(key, sizeof(unsigned char) * LEN2, 1, random);
   fclose(random);
   for (i = 0; i < LEN2; i += 1)
   {
      printf("%.2x", (unsigned char)key[i]);
   }
   printf("\n");
}
