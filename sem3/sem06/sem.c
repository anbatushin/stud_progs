#include <stdio.h>
#include <stdlib.h>

void compress(FILE *ifp, FILE *ofp);

void decompress(FILE *ifp, FILE *ofp);

void compress(FILE *ifp, FILE *ofp)
{

 char symbol;
 int num = 0;

 for(;;)
 {
  fread(&symbol, 1, 1, ifp);
  num++;
  if (symbol == EOF)
  {
   
  }
 }

 return;
}

int main(void)
{

 FILE *ifp1 = fopen("input.txt", "r");
 FILE *ofp1 = fopen("output.txt", "w");

 compress(ifp1, ofp1);

 fclose(ifp1);
 fclose(ofp1);

 FILE *ifp2 = fopen("output.txt", "r");
 FILE *ofp2 = fopen("re_input.txt", "w");

 decompress(ifp2, ofp2);

 fclose(ifp2);
 fclose(ofp2);

 return 0;
}
