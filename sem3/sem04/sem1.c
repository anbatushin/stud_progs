/* Узнать длину строк, выделить внутри функции новую память
   (malloc) и копировать туда строки */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *s1, char *s2);

int main(void)
{

 char *result = concat("string_1", "string_2");
 printf("%s\n", result);
 free(result);

 return 0;
}

char *concat(char *s1, char *s2)
{
 int len1 = strlen(s1);
 int len2 = strlen(s2);

 char *result = (char*) malloc(sizeof(char) * (len1 + len2 + 1));

 memcpy(result, s1, len1);
 memcpy(result + len1, s2, len2 + 1);

 return result;
}
