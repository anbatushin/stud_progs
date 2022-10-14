#include <stdio.h>

int main()
{
 int num, count = 0;
 for (num = 102; num <=987; num++)
  if ((num / 100) != (num % 10) && (num % 10) != (num % 100 / 10) && (num / 100) != (num % 100 / 10))
   count++;
 printf("Количество таких чисел:\t%d\n", count);

return 0;
}
