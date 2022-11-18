#include <stdio.h>
#include <stdlib.h>

typedef struct inode
{
 void *data;
 struct inode *next;
} inode;

typedef inode *queue;

void push_q(queue *q, void *value)
{
 queue tmp;
 tmp = (queue)malloc(sizeof(inode));
 tmp->data = value;
 tmp->next = NULL;
 if (*q == NULL)
 {
  *q = tmp;
  return;
 }
 for (; (*q)->next != NULL; q = &((*q)->next));
 (*q)->next = tmp;
}

void *pop_q(queue *q)
{
 if (*q == NULL)
  return NULL;
 queue tmp = *q;
 void *value = tmp->data;
 *q = (*q)->next;
 free(tmp);
 return value;
}

void clear_q(queue *q)
{
 queue tmp;
 for(tmp = *q; tmp != NULL; tmp = *q)
 {
  *q = tmp->next;
  free(tmp);
 }
}
