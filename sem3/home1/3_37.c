#include <stdio.h>
#include <math.h>

int main()
{
 float eps;
 float x;
 float i = 0.0;
 scanf("%f", &eps);
 do
 {
  i++;
  x = 1 + 1 / i;
 } while (pow(x, i+1) - pow(x, i) >= eps);
 printf("%4.3f\n", pow(x,i));
return 0;
}
