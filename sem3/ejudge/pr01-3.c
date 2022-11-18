#include <stdio.h>

int main(void)
{
 long long int a, b;
 int n;
 long long int i, j;

 scanf("%lld %lld %d", &a, &b, &n);
 for (i = a - 1; i < b; i++)
 {
  for (j = a - 1; j < b; j++)
  {
   if (i == a - 1 && j == a - 1)
    printf("%*c", n, ' ');
   else if (i == a - 1)
    printf(" %*lld", n, j);
   else if (j == a - 1)
    printf("%*lld", n, i);
   else
    printf(" %*lld", n, i * j);
  }
  printf("\n");
 }

 return 0;
}
