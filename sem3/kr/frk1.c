#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{

 if (fork() == 0)
 {
  if (fork() == 0)
  {
   printf("%d ", 1);
  }
  else
  {
   wait(NULL);
   printf("%d ", 3);
  }
 }
 else
 {
  wait(NULL);
  printf("%d ", 2);
 }

 return 0;
}
