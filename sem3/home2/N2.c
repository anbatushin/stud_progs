#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 3

void print(int mas[N][N]);
void mult(int mas_1[N][N], int mas_2[N][N], int res[N][N]);

int main()
{
 int A[N][N];
 int B[N][N];
 int C[N][N];

 int i, j;

 srand(time(NULL));
 for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
  {
   A[i][j] = rand() % 10;
   B[i][j] = rand() % 10;
  }

 print(A);
 print(B);

 mult(A, B, C);

 print(C);

return 0;
}

void print(int mas[N][N])
{
 int i, j;

 printf("Matrix:\n");

 for (i = 0; i < N; i++)
 {
  for (j = 0; j < N; j++)
   printf("%4d", mas[i][j]);
  printf("\n");
 }
}

void mult(int mas_1[N][N], int mas_2[N][N], int res[N][N])
{
 int i, j, k;

 for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
  {
   res[i][j] = 0;
   for (k = 0; k < N; k++)
    res[i][j] += mas_1[i][k] * mas_2[k][j];
  }
}




