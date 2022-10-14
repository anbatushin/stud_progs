#include <stdio.h>

int FindDel(int p)
{
 int fl = 0;
 int i = 2;
 while (i <= p / 2)
  {
   if (p % i == 0)
    {
     fl++;
     break;
    }
   i++;
  }
return (fl);
}

int main()
{
 int n, i = 1, p = 2;
 scanf("%d", &n);
 while (i <= n)
 {
  if (FindDel(p) == 0)
   {
    printf("%d\n", p);
    i++;
   }
  p++;
 }
return 0;
}
