/* char (*(*x[])())[5] */
/* typedef double (*PFD)() */

#include <stdio.h>
#include <math.h>

double f(double x)
{
 double f;
 f = sin(x) + cos(x) + sqrt(x);
 return f;
}

void integral(double a, double b, double(*f)(double))
{
 int i, n = 10000;
 double x, h, s = 0;
 h = (b-a)/n;
 for (x = a + h / 2, i = 0; i < n; i++, x += h)
  s += f(x) * h;
 printf("%7.4f\n", s);
}

 int main(void)
{

 double a, b;
 printf("Enter low and high edges:\n");
 scanf("%lf%lf", &a, &b);
 integral(a, b, f);

return 0;
}

