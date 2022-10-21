#include <stdio.h>
#include <time.h>

time_t d;

int main(void)
{
 time_t d = time(NULL);

 printf("%ld", d);

 return 0;
}
