#include <signal.h>
#include <sys/types.h>
#include <stdio.h>

int count = 1;
int ishandling = 0;

void SigHndlr(int s)
{
// ishandling = 1;
 printf("\n I Got SigInt %d time(s)\n", ++count);
 if (count == 5) signal(SIGINT, SIG_DFL);
 else signal(SIGINT, SigHndlr);
// ishandling = 0;
}

int main(int argc, char* argv[])
{

 signal(SIGINT, SigHndlr);
 while(1);

 return 0;
}
