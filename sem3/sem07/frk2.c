#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
 pid_t pid;
 if ((pid = fork()) == 0)
 {
  execlp("ps", "ps", (char*)NULL);
 }

/* wait(int *status) - returning pid_t (ожидание завершения ребенка) */

exit(0);
return 0;
}
