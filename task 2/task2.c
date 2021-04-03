#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEYSIZE 16

void main()
{
   long int test_time;
   int i;

   for(test_time = 1524002929; test_time <= 1524020929; test_time += 1)
   {
      char key[KEYSIZE];
      srand(test_time);
      for (i = 0; i < KEYSIZE; i += 1)
      {
         key[i] = rand() % 256;
         printf("%.2x", (unsigned char)key[i]);
      }
      printf("\n");
   }
}
