#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
 char* st;
 struct Node* next;
} Node;

typedef Node* list;

void check_lists(list L1, list L2)
{
 list tmp_1 = L1;
 list tmp_2 = L2;

 while (tmp_2 != NULL)
 {
  if (strcpy(tmp_1 -> st, tmp_2 -> st) == 0)
   tmp_1 = tmp_1 -> next;
  else
  {
   tmp_2 = tmp_2 -> next;
   tmp_1 = L1;
  }

  if (tmp_1 == NULL)
  {
   printf("L1 in L2\n");
   return;
  }
 }

 printf("L1 not in L2\n");
 return;
}

int main (void)
{
 return 0;
}
