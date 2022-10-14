#include <stdio.h>

#define MAX_STR 255

char sbuffer[MAX_STR];
int statistic[MAX_STR];

int main (void)
{
 char c;
 int len = 0;
 while ((c = getchar()) != '\n')
 {
  sbuffer[len] = c;
  len++;
 }

 for (int i = 0; i <= len - 2; i++)
  if ((sbuffer[i] == 'E')
      && (sbuffer[i + 1] == 'N')
      && (sbuffer[i + 2] == 'D'))
  {
    sbuffer[i] = '\0';
    len = i;
    break;
  }

 for (int i = 0; i <= len; i++)
 {
  c = sbuffer[i];
  statistic[c]++;
 }

 for (int i = 0; i <= 255; i++)
  if (((i >= 'a') && (i <= 'z')) || ((i >= 'A') && (i <= 'Z'))
      || ((i >= 0) && (i <= 9)))
   printf("%c\t%d\n", i, statistic[i]);
 printf("\n");
return 0;
}
