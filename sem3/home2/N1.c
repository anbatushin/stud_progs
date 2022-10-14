#include <stdio.h>

#define MAXLINE 1000

void getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
 int len;
 char line_1[MAXLINE];
 char line_2[MAXLINE];

 getlines(line_1, MAXLINE);
 getlines(line_2, MAXLINE);

 printf("line 1: %s\n line 2: %s\n", line_1, line_2);

 copy(line_2, line_1);

 printf("line 1: %s\n line 2: %s\n", line_1, line_2);

return 0;
}

void getlines(char line[], int lim)
{
 int c, i;

 for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++)
  line[i] = c;
 if (c == '\n')
 {
  line[i] = c;
  i++;
 }

 line[i] = '\0';
}

void copy(char to[], char from[])
{
 int i = 0;
 while ((to[i] = from[i]) != '\0')
  i++;
}










