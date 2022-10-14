#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
 int value;
 struct Node *next;
} Node;

typedef Node *list;

list head = NULL;

void push_st(void)
{

 int value;
 list tmp = (list)malloc(sizeof(Node));
 if (tmp == NULL)
 {
  printf("Overflow\n");
  exit(EXIT_FAILURE);
 }

 printf("Enter the new object: ");
 scanf("%d", &value);

 tmp->value = value;
 tmp->next = head;
 head = tmp;

 printf("Pushed: %d\n", value);

return;
}

void pop_st(void)
{

 list tmp;
 int value;
 if (head == NULL)
 {
  printf("Underflow\n");
  exit(EXIT_FAILURE);
 }

 tmp = head;
 head = head->next;
 value = tmp->value;
 free(tmp);
 printf("Next object was poped from stack: %d\n", value);

return;
}

void print_st(void)
{
 list tmp = head;
 printf("stack -> ");
 while (tmp != NULL)
 {
  printf("%d ", tmp->value);
  tmp = tmp->next;
 }

 printf("\n");
 return;
}

void delete_st(void)
{

 list tmp;
 int value;

 if (head == NULL)
 {
  printf("The stack is empty\n");
  return;
 }

 tmp = head;
 head = head->next;
 value = tmp->value;
 free(tmp);
 printf("Next object was deleted from the stack: %d\n", value);

}

int check_empty(void)
{
 return (head == NULL);
}


void check_st(void)
{
 if (check_empty())
  printf("Stack is empty\n");
 else
  printf("Stack is not empty\n");
 return;
}

void first_st(void)
{
 if (check_empty())
 {
  printf("Stack is empty\n");
  return;
 }

 printf("The first object in the stack: %d\n", head->value);
 return;
}

void ending_st(void)
{

 while (head != NULL)
  delete_st();

 return;
}

void Interface_mode(void)
{

 char index;
  printf("Choose the mode:\n"),
  printf ("1: Check stack (empty or not)\n"),
  printf ("2: Pop (pop the value to stack)\n"),
  printf ("3: Push (push the value from stack)\n"),
  printf ("4: Delete (delete the first one)\n"),
  printf ("5: First (print the first one (without deleting))\n"),
  printf ("6: Print (print the full stack)\n"),
  printf ("7: exit (clean the stack and get off)\n");

for (;;)
{
 scanf("%c", &index);
 switch (index)
 {
  case '1': check_st(); break;
  case '2': pop_st(); break;
  case '3': push_st(); break;
  case '4': delete_st(); break;
  case '5': first_st(); break;
  case '6': print_st(); break;
  case '7': ending_st(); goto EXIT;
 }
}
EXIT:
 printf("Goodbye\n");
 return;
}

int main(void)
{

 Interface_mode();

 return 0;
}
