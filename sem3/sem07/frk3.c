#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main (void)
{

 if (fork())
 {
  wait(NULL);
  printf("1 ");
  printf("\n");
 }
 else if (fork())
 {
  wait(NULL);
  printf("2 ");
 }
 else
  printf("3 ");

return 0;

}
