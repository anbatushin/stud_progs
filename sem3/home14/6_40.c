/* There is not the full program - just see the functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode
{
 char *s;
 lnode *next;
} lnode;

typedef lnode *list;

list New_List(list l1, list l2)
{

 list l3 = NULL;
 list tmp;
 for (; l1 != NULL; l1 = l1->next)
 {
  tmp = l2;
  for (; tmp != NULL && l1->s != tmp->s; tmp = tmp->next);

  if (tmp == NULL)
  {
   tmp2 = (list)malloc(sizeof(lnode));
   memcpy(tmp2->s, l1->s, sizeof(char*));
   tmp2->next = l3;
   l3 = tmp2;
  }
 }

 return l3;
}

int main(void)
{
 return 0;
}
