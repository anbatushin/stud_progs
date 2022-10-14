/* Structures */
/* struct point
   {
    int x;
    int y;
   }
   int main(void)
   {
    struct point q;
    q.x = 1;
    q.y = 5;
   }
___________________________
typedef struct point
{
 int x;
 int y;
} ptype;

ptype q;
___________________________
*/

#include <stdio.h>

typedef struct point
{
 int x;
 int y;
} ptype;

int main(void)
{

 ptype a = {2, 25};
 ptype *p = &a;
 int *q;

 q = (int*)p;

 printf("%d %d\n", q[0], q[1]);
 printf("%ld\n", sizeof(ptype));

return 0;
}
