#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
 int value;
 struct Node *next;
} Node;

typedef Node *list;
list last, first;

list New_Node_q(int value)
{

 list tmp = (list)malloc(sizeof(Node));
 if (tmp != NULL)
 {
  tmp->value = value;
  tmp->next = NULL;
  return tmp;
 }
 else
 {
  printf("Overflow\n");
  exit(EXIT_FAILURE);
 }

}

int check_empty_q()
{
 return (last == NULL && first == NULL);
}

void check_q()
{
 if (check_empty_q())
  printf("The queue is empty\n");
 else
  printf("The queue is not empty\n");

 return;
}

void push_q()
{

 int value;
 printf("Enter the new object:\t");
 scanf("%d", &value);

 list tmp = New_Node_q(value);
 printf("Pushed: %d\n", value);

 if (first == NULL)
 {
  first = tmp;
  last = tmp;
 }
 else
 {
  last->next = tmp;
  last = tmp;
 }

}

int pop_q()
{

 if (first == NULL)
 {
  printf("Underflow\n");
  exit(EXIT_FAILURE);
 }

 list tmp = first;
 printf("Data: %d\n", tmp->value);

 first = first->next;

 if (first == NULL)
  last = NULL;

 int value = tmp->value;
 free(tmp);
 return value;

}

void first_q(void)
{

 if (first != NULL)
  printf("First object is: %d\n", first->value);
 else
  exit(EXIT_FAILURE);

}

void print_q(void)
{

 list tmp;
 if (check_empty_q())
 {
  printf("queue is empty now\n");
  return;
 }

 for (tmp = first; tmp != NULL; tmp = tmp->next)
  printf("%d ", tmp->value);

 printf("\n");

 return;
}

void delete_q(void)
{

 list tmp;
 int value;

 if (check_empty_q())
 {
  printf("queue is empty now\n");
  return;
 }

 value = first->value;
 tmp = first;
 first = first->next;
 free(tmp);

 printf("The next object was deleted from queue: %d\n", value);

 return;
}

void ending_q(void)
{

 while (first != NULL)
  delete_q();

}

void Start_Interface_q(void)
{

 char index;
  printf("Choose the mode:\n"),
  printf ("1: Check queue (empty or not)\n"),
  printf ("2: Pop (pop the value to queue)\n"),
  printf ("3: Push (push the value from queue)\n"),
  printf ("4: Delete (delete the first one)\n"),
  printf ("5: First (print the first one (without deleting))\n"),
  printf ("6: Print\n (print the full queue"),
  printf ("7: exit (clean the queue and get off)\n");

for (;;)
{
 scanf("%c", &index);
 switch (index)
 {
  case '1': check_q(); break;
  case '2': pop_q(); break;
  case '3': push_q(); break;
  case '4': delete_q(); break;
  case '5': first_q(); break;
  case '6': print_q(); break;
  case '7': ending_q(); goto EXIT;
 }
}
EXIT:
 printf("Goodbye\n");
 return;
}

int main(void)
{

 Start_Interface_q();

 return 0;
}
