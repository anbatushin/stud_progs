#include <stdlib.h>
#include <stdio.h>

typedef struct tnode
{
 int data;
 struct tnode *left;
 struct tnode *right;
} tnode;

typedef tnode *tree;

int Number_uz(tree *T)
{
 int N;
 int length = 0;
 int num = 0;

 printf("Enter the level: ");
 scanf("%d", &N);

 if ((N < 0) || (*T == NULL))
  return 0;

 push_st(*T);

 for (;check_st() != NULL;)
 {
  if (length == N)
   num++;

  if (left != NULL)
  {
   push_st(*T);
   *T = (*T)->left;
   length++;
  }
  else if (right != NULL)
  {
   push_st(*T);
   *T = (*T)->right;
   length++;
  }
  else
  {
   *T = pop_st();
   length--;
  }
 }

 return num;
}

void addtree(tree *T, int value)
{
 if (*T == NULL)
 {
  *T = (tree)malloc(sizeof(tnode));
  (*T)->data = value;
  (*T)->left = NULL;
  (*T)->right = NULL;
  return;
 }

 if ((*T)->data > value)
  addtree(&((*T)->left), value);
 else
  addtree(&((*T)->right), value);

}

void Print_Tree(tree *T)
{
  if (T != NULL)
  {
    printf("%d ", T->data);
    treeprint(tree->left); //Рекурсивная функция для левого поддерева
    treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}

int main(void)
{
 for (int i = 0; i < 10; i++)
  addtree(T, i);

 printf("There are: %d", Number_uz());
}
