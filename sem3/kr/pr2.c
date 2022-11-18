#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

 int fd[2];
 pipe(fd);
 pid_t pid_12 = fork();
 if (pid_12 == 0)
 {
  close(fd[0]);
  int f1_fd = open(argv[4], O_RDONLY);
  if (f1_fd == -1)
   exit(1);
  dup2(f1_fd, 0);
  close(f1_fd);
  dup2(fd[1], 1);
  close(fd[1]);
  execlp(argv[1], argv[1], NULL);
  exit(1);
 }

 return 0;
}
