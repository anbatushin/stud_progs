#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

void obhod(const char *dirPath)
{

 printf("Current = %s\n", dirPath);

 DIR *dir = opendir(dirPath);
 if (!dir)
 {
  return;
 }

 struct dirent *dd;
 char path[PATH_MAX];
 while((dd = readdir(dir)))
 {
  int slen = snprintf(path, sizeof(path), "%s/%s", dirPath, dd->d_name);
  if (slen + 1 > sizeof(path) || dd->d_name[0] == '.')
   continue;

  struct stat stb;
  if (stat(path, &stb) < 0 || S_ISREG(stb.st_mode)) continue;

//  if (S_ISDIR(stb.st_mode) && !S_ISLNK(stb.st_mode)) obhod(path);

  obhod(path);
 }

 closedir(dir);
 return;
}

int main(int argc, char *argv[])
{

 DIR *dir;
 struct dirent *dd;
 const char *name = ".";
 if (argc > 1)
  name = argv[1];

 obhod(name);

 closedir(dir);

 return 0;
}
