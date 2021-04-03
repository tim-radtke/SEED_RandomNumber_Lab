#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEYSIZE 16

void main()
{
   int i;
   char key[KEYSIZE];

   printf("%11d\n", (long long) time(NULL));
   srand(time(NULL));

   for (i = 0; i < KEYSIZE; i += 1)
   {
      key[i] = rand() % 256;
      printf("%.2x", (unsigned char)key[i]);
   }
   printf("\n");
}
