#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv)
{

 pid_t pid;

 printf("PID = %d; PPID = %d\n", getpid(), getppid()); /* PID и PPID */

/* Копирует процесс и запускает */
 pid = fork();
 printf("PID = %d; PPID = %d\n", getpid(), getppid()); /* PID и PPID */
 printf("Returned %d\n", pid);
 return 0;
}
