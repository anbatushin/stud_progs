#include <stdio.h>

enum a {c1 = 1, c2 = 2};
enum b {c3 = 3};
enum a a;

int main(void)
{
 enum a {c3 = 4};
 enum a b = c1;
 a = c3;

 printf("%d\n", a);
 return 0;
}
