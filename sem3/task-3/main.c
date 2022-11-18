#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

enum
{
 NUM_CHAR = 10,
 SIZE_CHAR = NUM_CHAR + 1,
 SIZE = 100
};

//typedef enum {Start, Stop, Word, Great_1, Great_2, NewLine} process;

typedef struct Node
{
 char *letter;
 struct Node *next;
 struct Node *prev;
} Node;

typedef Node *list;

//process State = Start;

list lst;
char str[SIZE_CHAR], str2[SIZE_CHAR];
char *buf;

int c;
int countchar;
int sizebuf;
int curbuf;
int curlist;

int getsymbol(void)
{
 int c = str[curbuf];
 curbuf++;

 return c;
}

void createlist(void)
{

 list lst = (list)malloc(sizeof(Node));
 lst->next = NULL;
 lst->prev = NULL;
 curlist = 0;

 return;
}

void addlist(void)
{

 list tmp = (list)malloc(sizeof(Node));
 printf("\n!!!!!str: %s!!!!!\n", str);
 strcpy(tmp->letter, str);

 printf("LOL");

 tmp->next = lst;
 tmp->prev = NULL;
 lst->prev = tmp;
 lst = tmp;

 curlist++;

 return;
}

void printlist(void)
{

 list tmp;

 while(lst->next)
 {
  printf("%s\n", lst->letter);
  tmp = lst;
  lst = lst->next;
  lst->prev = NULL;
  free(tmp);
 }

 return;
}

void deletelist(void)
{

 free(lst);
 return;
}

void newbuf(void)
{

 buf = realloc(buf, countchar += NUM_CHAR);

 return;
}

void addbuf(void)
{
 buf[countchar-1] = c;
}

int main(void)
{
 int fl;
 int count = 0;

 createlist();
  buf = (char*)malloc(sizeof(NUM_CHAR * sizeof(char)));
 for(;;)
 {
  if (fscanf(stdin, "%10s", str) == EOF) break;
  printf("\nstring: %s\n", str);

  while ((c = getsymbol()) != '\0')
  {
   countchar++;
   printf("\nc: %d\n", c);
   if (countchar > NUM_CHAR)
   {
    newbuf();
    countchar -= NUM_CHAR;
   }

   addbuf();
  }

  printf("\nbuf: %s\n", buf);
 }

 printf("\ncount: %d\n", count);

 deletelist();

 return 0;
}
