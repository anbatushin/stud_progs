typedef struct node {
    void *data;
    struct inode *next;
} node;

typedef node *queue;

void push_q(queue *q, void *data);

void *pop_q(queue *q);

int size_q(queue q);

void clear_q(queue *q);
