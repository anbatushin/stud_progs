#include <stdio.h>

int main(void)
{
 long int length = 999999;
 char c;
 int i;
 FILE *fp;
 char name[] = "test.txt";
 fp = fopen(name, "w");

for (i = 0; i < 100; i++)
 fprintf(fp, "%d", i);

 fprintf(fp, "%ld", length);
 fclose(fp);

 fp = fopen(name, "r");
 while (fscanf(fp, "%c", &c) != EOF)
  ;
 i = ftell(fp);
 length = 0;
 fseek(fp, i - sizeof(long int), SEEK_SET);
 fscanf(fp, "%ld", &length);
 printf("\n%ld\n", length);

 fclose(fp);
 return 0;
}
