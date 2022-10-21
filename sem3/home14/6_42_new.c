#include "q_42.h"

void push_q(queue *q, void *value)
{
 queue new = (queue)malloc(sizeof(inode));
 new->data = value;
 new->next = NULL;
 if (*q == NULL)
 {
  *q = new;
  return;
 }

 for (; (*q)->next != NULL; q = &((*q)->next));

 (*q)->next = new;

 return;
}

void *pop_q(queue *q)
{
 if (*q == NULL)
  return NULL;

 queue fo = *q;
 void *value = fo->data;
 *q = (*q)->next;
 free(fo);
 return value;
}

int size_q(queue q)
{
 int n = 0;
 for(; q != NULL; q = q->next)
  ++n;
 return n;
}

void clear_q(queue *q)
{
 queue del;
 for(del = *q; del != NULL; del = *q)
 {
  *q = del->next;
  free(del);
 }

 return;
}
