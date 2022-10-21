#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(int argc, char* argv[])
{

 if (argc < 2)
  fprintf(stderr, "NO");

 DIR *dir = opendir(argv[1]);
 if (!dir)
 {
  fprintf(stderr, "error: %s\n", strerror(errno));
  exit(1);
 }

 struct dirent *dd;
 while (dd = readdir(dir))
 {
  printf("%lu %s\n", dd->d_ino, dd->d_name);
 }

 closedir(dir);

 return 0;
}
