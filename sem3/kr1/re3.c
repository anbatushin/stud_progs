#include <stdio.h>
#include <stdlib.h>

void change(FILE *ifd, FILE *ofd)
{

 int n;
 int min, max, min_pos, max_pos, pos;

 pos = 1;
 max_pos = 1;
 min_pos = 1;

 while (fscanf(ifd, "%d", &n) != EOF)
 {
  if (pos == 1)
  {
   min = n;
   max = n;
  }

  if (n < min)
  {
   min = n;
   min_pos = pos;
  }

  if (n > max)
  {
   max = n;
   max_pos = pos;
  }

  pos++;
 }


 printf("min: %d, min_pos: %d, max: %d, max_pos: %d\n", min, min_pos, max, max_pos);
 return;
}

int main(void)
{
 FILE *ifd = fopen("input.txt","r");
 FILE *ofd = fopen("output.txt", "w");

 change(ifd, ofd);

 fclose(ifd);
 fclose(ofd);
 return 0;
}
