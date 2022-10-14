#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{

 if (argc != 3)
  printf("Incorrect input...\n");

 double (*fp)(double);

 if (!strcmp(argv[1], "sin"))
  fp = sin;
 else
  if (!strcmp(argv[1], "cos"))
   fp = cos;
  else
   if (!strcmp(argv[1], "sqrt"))
    fp = sqrt;
   else
    if (!strcmp(argv[1], "exp"))
     fp = exp;

 printf("%lf\n", fp(atof(argv[2])));

 return 0;
}
