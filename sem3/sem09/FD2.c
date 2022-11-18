#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
 char buf[1024];
 int fd1, fd2;
 ssize_t n;
 struct stat s;
 if ((fd1 = open(argv[1], O_RDONLY)) == -1)
 {
  printf("ERROR OPEN FILE \n");
  return -1;
 }
 stat(argv[1], &s);
 if((fd2 = creat(argv[2], s.st_mode)) == -1)
 {
  printf("ERROR CREATE FILE\n");
  return -1;
 }

 while (n = read(fd1, buf, 1024) > 0)
 {
  write(fd2, buf, n);
 }

 close(fd1);
 close(fd2);
}
