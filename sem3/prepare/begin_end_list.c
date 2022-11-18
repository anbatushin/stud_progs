#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
 int data;
 struct Node* next;
} Node;

typedef Node* list;

void push_front(list *lst, char c)
{
 list tmp = (list)malloc(sizeof(Node));
 tmp->data = c;
 tmp->next = *lst;
 *lst = tmp;
 return;
}

void push_back(list *lst, char c)
{
 while (*lst != NULL)
  lst = &(*lst)->next;
 *lst = (list)malloc(sizeof(Node));
 (*lst)->data = c;
 (*lst)->next = NULL;
}

/*void clear_lst(list *lst)
{
 list tmp;
 while (lst)
 {
  tmp = *lst;
  *lst = (*lst)->next;
  free(tmp);
 }
}*/

int main(void)
{
 list lst = NULL;

 push_back(&lst, 'a');
 push_front(&lst, 's');
 push_back(&lst, 't');

 list p = lst;

 while (p != NULL)
 {
  printf("%c", p->data);
  p = p->next;
 }

 printf("\n");

 return 0;
}
