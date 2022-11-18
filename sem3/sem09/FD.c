/* Файловые дескрипторы */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
 int fd;
 if (fd = open("a.out", O_WRONLY, O_CREAT, O_EXCL, 0644))
 {
 }

 int close (int fd);

 return 0;
}
