#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
 int N;
 scanf("%d", &N);

 for (int i = 0; i < N; i++)
 {

  printf("%d ", i);
  if (i == N - 1)
   printf("\n");
  fflush(stdout);

  if (fork())
  {
   wait(NULL);
   exit(0);
  }
 }

 return 0;
}
