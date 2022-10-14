/* There is not the full program - just see the functions */

#include <stdio.h>
#include <stdlib.h>

#define LISTS 10

typedef struct Node
{
 int data;
 struct Node *list;
} Node;

void Create_List(Node **head);
void Print_List(Node **head);
void Swap_First_Last(Node **head);
void Find_And_Delete(Node **head, int value);
void Find_And_Delete_All(Node **head, int value);

void Create_List(Node **head)
{

 for (int i = 0; i < LISTS; i++)
 {
  Node *tmp = (Node*)malloc(sizeof(Node));
  printf("%d: ", i);
  scanf("%d", &(tmp->data));
  printf("\n");
  tmp->list = (*head);
  *head = tmp;
 }

 return;
}

void Print_List(Node **head)
{

 if (*head == NULL)
 {
  printf("Nothing to print\n");
  return;
 }

 Node *tmp;
 tmp = *head;

 while (tmp != NULL)
 {
  printf("%d\t", tmp->data);
  tmp = tmp->list;
 }
 printf("\n");

 return;
}

void Swap_First_Last(Node **head)
{

 if (*head == NULL)
  { printf("head");return;
}
 Node *tmp, *tmp2;
 tmp = (*head)->list;

 if (tmp == NULL)
 { printf("tmp"); return;
}
 if (tmp->list == NULL)
 {
  (*head)->list = NULL;
  tmp->list = *head;
  *head = tmp;
 }
 else
 {
  while (tmp->list != NULL)
  {
   tmp2 = tmp;
   tmp = tmp->list;
  }

  tmp2->list = *head;
  tmp->list = (*head)->list;
  (*head)->list = NULL;
  *head = tmp;
 }

 return;
}

void Find_And_Delete(Node **head, int value)
{

 Node *tmp, *tmp2;

 if ((*head)->data == value && (*head)->list == NULL)
 {
  free(*head);
 }

 if ((*head)->data == value)
 {
  tmp = *head;
  *head = tmp->list;
  free(tmp);
  return;
 }

 tmp = *head;
 tmp2 = (*head)->list;

 if (tmp2 == NULL)
  return;

 while (tmp2 != NULL)
 {
  for (; (tmp2 != NULL) && (tmp2->data != value); tmp2 = ((tmp2)->list), tmp = tmp->list);
  if (tmp2 == NULL)
   return;
  tmp->list = tmp2->list;
  free(tmp2);
  return;
 }

 return;
}

void Find_And_Delete_All(Node **head, int value)
{

 Node *tmp, *tmp2;
 tmp = (*head);
 tmp2 = tmp;

 while (tmp != NULL)
  if (tmp->data == value)
   if(tmp == tmp2)
   {
    tmp = (*head)->list;
    *head = (*head)->list;
    free(tmp2);
    tmp2 = tmp;
   }
   else
   {
    tmp2->list = tmp->list;
    free(tmp);
    tmp = tmp2->list;
   }
  else if (tmp == tmp2)
   tmp = tmp->list;
   else
   {
    tmp = tmp->list;
    tmp2 = tmp2->list;
   }

 return;
}

int main(void)
{

 Node *head = NULL;

 Create_List(&head);

 Print_List(&head);

 Swap_First_Last(&head);

 Print_List(&head);

 int value;
 scanf("%d", &value);

 //Find_And_Delete(&head, value);

 //Print_List(&head);

 Find_And_Delete_All(&head, value);

 Print_List(&head);

 return 0;
}
