#include <stdio.h>
#include <stdlib.h>

void change(FILE* ifd, FILE* ofd)
{
 char* n;
 int fl;

 fgets(n, ifd);

 return;
}


int main(void)
{

 FILE *ifd = fopen("input.txt", "r");
 FILE *ofd = fopen("output.txt", "w");

 change(ifd, ofd);

 fclose(ifd);
 fclose(ofd);

 return 0;
}
