#include <stdio.h>

int countCPlus(void)
{
 enum {Start, C, CPlus, Stop};
 int count = 0;
 int c;
 int v = Start;
 while(c = getchar())
  switch(v)
  {
   case Start:
    if (c == 'C') v = C;
    else if (c == EOF) v = Stop;
    break;
   case C:
    if (c == '+') v = CPlus;
    else if (c == EOF) v = Stop;
    else if (c != 'C') v = Start;
    break;
   case CPlus:
    if (c == '+')
    {
     count++;
     v = Start;
    }
    else if (c == EOF) v = Stop;
    else if (c == 'C') v = C;
    else v = Start;
    break;
   case Stop:
    return count;
  }
}

int main (void)
{

 printf("%d\n", countCPlus());

 return 0;
}
