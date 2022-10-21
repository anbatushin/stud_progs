#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{

 if (argc < 1)
 {
  fprintf(stderr, "NO");
  exit(2);
 }

 DIR *dir = opendir(argv[1]);
 if (!dir)
 {
  fprintf(stderr, "error: %s\n", strerror(errno));
  exit(1);
 }

 struct dirent *dd;

 char path[PATH_MAX];

 while (dd = readdir(dir))
 {
  int slen = snprintf(path, sizeof(path), "%s/%s", argv[1], dd->d_name);
  if (slen + 1 > sizeof(path))
   continue;

  printf("%s %d %lu %s\n", path, slen, dd->d_ino, dd->d_name);
  struct stat stb;
  if (stat(path, &stb) < 0) continue;
  printf("stat: %lu %lu\n", stb.st_ino, stb.st_dev);
 }

 closedir(dir);

 return 0;
}
