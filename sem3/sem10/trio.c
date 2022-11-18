#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[])
{

 pid_t p1, p2, p3;
 int ifd;
 int fd[2];
 pipe(fd);

 if (fork() == 0)
 {
  
 }


 return 0;
}
