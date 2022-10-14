#include <stdio.h>

int main()
{
 int n = 1;
 float a, sum = 0.0;

 scanf("%f", &a);
 while (sum <= a)
  { printf("%f\n", sum);
    sum += (1.0 / n++);
  }
 printf("%d\n", --n);

return 0;
}
