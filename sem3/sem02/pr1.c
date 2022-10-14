#include <stdio.h>

int fibbonachi (int n)
{
 if (n == 1 || n == 2)
  return 1;
 return fibbonachi(n - 1) + fibbonachi(n - 2);
}

int main(void)
{
 int n;
 scanf("%d", &n);
 for (int i = 1; i <= n; i++)
  printf("%d\n", fibbonachi(i));

return 0;
}
