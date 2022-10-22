#include <stdio.h>

int main(void)
{
 int sum = 0;
 int symbol;

 while ((symbol = getchar()) != -1)
 {
  if ((symbol <= '9') && (symbol >= '0'))
   sum += symbol - '0';
  else if ((symbol <= 'f') && (symbol >= 'a'))
   sum += symbol - 'a' + 10;
  else if ((symbol <= 'F') && (symbol >= 'A'))
   sum += symbol - 'A' + 10;
 }

 printf("%d\n", sum);

 return 0;
}
