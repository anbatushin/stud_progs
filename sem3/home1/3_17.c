#include <stdio.h>
#include <math.h>

int main ()
{
 float a, b, c, d;
 printf("Введите a, b, c:\n");
 scanf("%f%f%f", &a, &b, &c);
 if (a == 0)
  if (b == 0)
   if (c == 0)
    printf("Бесконечно много решений\n");
   else
    printf("Нет решений\n");
  else
   if (c != 0)
    printf("Один корень:\t%3.1f\n", c / -b);
   else
    printf("Один корень:\t0\n");
 else
 {

 d = b * b - 4 * a * c;
 if (d == 0)
 {
  printf("Один корень:\t%3.1f\n", -b / (2 * a));
 } else
 {
  printf("Два корня:\t");
  if (d > 0)
   printf("x1 = %3.1lf\tx2 = %3.1lf\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
  else
  {
   d = fabs(d);
   printf("x1 = %3.1f + %3.1lfi\tx2 = %3.1lf - %3.1lfi\n", -b / (2 * a), sqrt(d) / (2 * a), -b / (2 * a), sqrt(d) / (2 * a));
  }
 }

 }
 return 0;
}
