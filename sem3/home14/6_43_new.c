#include <stdio.h>
#include <stdlib.h>

typedef struct inode
{
 void *data;
 struct inode *next;
} inode;

typedef inode *stack;

void push_s(stack *
