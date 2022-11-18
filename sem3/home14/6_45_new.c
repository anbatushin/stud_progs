#include "6_42_new.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
} tnode;

typedef tnode *tree;

int t_level(tree T, int N);

void t_print(tree T);

void t_add(tree *T, int value);

void t_clear(tree *T);

int t_level(tree T, int N)
{
 if ((N < 0) || (T == NULL))
  return 0;

 int bef = 1;
 int aft = 0;
 queue q = NULL;
 push_q(&q, T);

 for(int i = 0; (q != NULL) && (i < N); i++)
 {
  tree tmp;
  for(; bef > 0; bef--)
  {
   tmp = (tree)pop_q(&q);
   if (tmp->left != NULL)
   {
    aft++;
    push_q(&q, tmp->left);
   }
   if (tmp->right != NULL)
   {
    aft++;
    push_q(&q, tmp->right);
   }
  }

  if (aft == 0)
   break;

  bef = aft;
  aft = 0;
 }

 clear_q(&q);

 return bef;
}

void t_print(tree T)
{
 int bef = 1;
 int aft = 0;
 queue q = NULL;

 push_q(&q, T);

 for(;;)
 {
  tree tmp;
  for(; bef > 0; bef--)
  {
   tmp = (tree)pop_q(&q);
   printf("%d ", tmp->data);
   if (tmp->left != NULL)
   {
    aft++;
    push_q(&q, tmp->left);
   }
   if (tmp->right != NULL)
   {
    aft++;
    push_q(&q, tmp->right);
   }
  }
  if (aft == 0)
   break;

  printf("\n");
  bef = aft;
  aft = 0;
 }

 printf("\n");
 clear_q(&q);

}

void t_add(tree *T, int value)
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
  t_add(&((*T)->left), value);
 else
  t_add(&((*T)->right), value);
}

void t_clear(tree *T)
{
 if (*T == NULL)
  return;
 t_clear(&((*T)->left));
 t_clear(&((*T)->right));
 free(*T);
}

int main(void)
{
 int N;
 int num;
 tree T = NULL;

 scanf("%d", &num);
 scanf("%d", &N);
 printf("\n");

 for (; num > 0; num--)
  t_add(&T, rand() % 100);

 t_print(T);
 printf("----------\n");

 num = t_level(T, N);
 printf("%d\n", num);
 t_clear(&T);
 return 0;
}
