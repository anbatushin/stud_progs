#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

 int fd[2];
 pipe(fd);
 if (fork() == 0)
 {
  dup2(fd[1], 1);
  close(fd[1]);
  close(fd[0]);
  execlp(argv[1], argv[1], (char*)0);
  exit(1);
 }

 if (fork() == 0)
 {
  dup2(fd[0], 0);
  close(fd[0]);
  close(fd[1]);
  execlp(argv[2], argv[2], (char*)0);
 }

 close(fd[0]);
 close(fd[1]);

 wait(NULL);
 wait(NULL);
 exit(0);

 return 0;
}
