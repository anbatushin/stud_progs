#include <stdio.h>
#include <stdlib.h>

void mas(unsigned int* m, int N)
{
 int* p = m;
 unsigned int tmp;

 for (int i = 0; i < N; i++)
 {
  tmp = *(p);
  if (tmp >= 'A' && tmp <= 'Z' || tmp >= 'a' && tmp <= 'z')
   *(p+3) = 0;
 }
}

