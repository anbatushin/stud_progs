#include <stdio.h>
#include <time.h>

int main(void)
{

 time_t cur = time(NULL);
 printf("%ld %zu\n", cur, sizeof(cur));

 struct tm ttm;
 localtime_r(&cur, &ttm);

 printf("%d-%d-%d %d:%d:%d %d \n",
        ttm.tm_year + 1900, ttm.tm_mon + 1, ttm.tm_mday,
        ttm.tm_hour, ttm.tm_min, ttm.tm_sec, ttm.tm_isdst);

 ttm.tm_mday += 90;
 ttm.tm_isdst = -1;

 time_t lat90 = mktime(&ttm);
 printf("%ld %zu\n", lat90, sizeof(lat90));

 printf("%d-%d-%d %d:%d:%d %d \n",
        ttm.tm_year + 1900, ttm.tm_mon + 1, ttm.tm_mday,
        ttm.tm_hour, ttm.tm_min, ttm.tm_sec, ttm.tm_isdst);


 return 0;
}

