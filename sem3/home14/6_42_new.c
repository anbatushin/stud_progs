#include "6_42_new.h"

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
 for (; (*q) -> next != NULL; q = &((*q) -> next));
  (*q) -> next = new;
}

void *getqu(queue *q)
{
    if (*q == NULL){
        return NULL;
    }
    queue fo = *q;
    void *value = fo -> data;
    *q = (*q) -> next;
    free(fo);
    return value;
}

int sizequ(queue q)
{
    int n = 0;
    for(; q != NULL; q = q -> next){
        ++n;
    }
    return n;
}

void clearqu(queue *q)
{
    queue del;
    for(del = *q; del != NULL; del = *q){
        *q = del -> next;
        free(del);
    }
}
