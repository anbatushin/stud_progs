/* There is not the full program - just see the functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode
{
 struct data *p;
 struct lnode *next;
} lnode;

typedef struct data
{
 double f;
 char *s[2];
} data;

typedef lnode *list;

list Copy(list l1)
{
 list l2 = NULL;
 list tmp;

 if (l1 != NULL)
 {
  tmp = (list)malloc(sizeof(lnode));
  memcpy(tmp->p, l1->p, sizeof(data));
  l1 = l1->next;
  l2 = tmp;
 }

 while (l1 != NULL)
 {
  list tmp2 = (list)malloc(sizeof(lnode));
  memcpy(tmp2->p, l1->p, sizeof(data));
  l1 = l1->next;
  tmp->next = tmp2;
  tmp = tmp->next;
 }

 tmp->next = NULL;
 return l2;
}

int main(void)
{
 return 0;
}
