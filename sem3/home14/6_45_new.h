#include <stdio.h>
#include "6_42_new.h"

typedef struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
} tnode;

typedef tnode *tree;
