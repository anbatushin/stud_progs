#include "6_42_new.h"
#include <time.h>

typedef struct tnode
{
 int data;
 struct tnode *left;
 struct tnode *right;
} tnode;

typedef tnode *tree;

int count_level_tree(tree tr, int number)
{
    if ((number < 0) || (tr == NULL)){
        return 0;
    }
    int n, last = 1, next = 0;
    queue q = NULL;
    push_q(&q, tr);
    for(n = 0; (q != NULL) && (n < number); ++n){
        tree buff;

        for(; last > 0; --last){
            buff = (tree)pop_q(&q);
            if (buff -> left != NULL){
                ++next;
                push_q(&q, buff -> left);
            }
            if (buff -> right != NULL){
                ++next;
                push_q(&q, buff -> right);
            }
        }
        if (next == 0){
            break;
        }
        last = next;
        next = 0;
    }
       clear_q(&q);
    return last;
}

void printqu(queue q)
{
    for(; q != NULL; q = q -> next){
        printf("%d ", ((tree)(q -> data)) -> data);
    }
    printf("\n");
}

void printtr(tree tr)
{
    int last = 1, next = 0;
    queue q = NULL;
    push_q(&q, tr);
    for(;;){
        tree buff;
        for(; last > 0; --last){
            buff = (tree)pop_q(&q);
            printf("%d ", buff -> data);
            if (buff -> left != NULL){
                ++next;
                push_q(&q, buff -> left);
            }
            if (buff -> right != NULL){
                ++next;
                push_q(&q, buff -> right);
            }
        }
        if (next == 0){
            printf("%d ", buff -> data);
            break;
        }
        printf("\n");
        last = next;
        next = 0; 
    }
    printf("\n");
    clear_q(&q);
}

void addtr(tree *tr, int value)
{
    if (*tr == NULL){
        *tr = (tree)malloc(sizeof(tnode));
        (*tr) -> data = value;
        (*tr) -> left = NULL;
        (*tr) -> right = NULL;
        return;
    }
    if ((*tr) -> data > value){
        addtr(&((*tr) -> left), value);
    } else {
        addtr(&((*tr) -> right), value);
    }
}

void cleartr(tree *tr)
{
    if (*tr == NULL){
        return;
    }
    cleartr(&((*tr) -> left));
    cleartr(&((*tr) -> right));
    free(*tr);
}

int main(void)
{
    tree tr = NULL;
    int n;
    scanf("%d", &n);
    printf("\n");
    srand(time(NULL));
    for (; n > 0; --n){
        addtr(&tr, 1+(int)(100.0*rand()/(RAND_MAX+1.0)));
    }
    printtr(tr);
    printf("----------\n");
    n = count_level_tree(tr, 2);
    printf("%d\n", n);
    cleartr(&tr);
    return 0;
}

