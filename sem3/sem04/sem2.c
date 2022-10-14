#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **invertM(double **mas, int N);
double **transpM(double **mas, int N, int M);

int main(void)
{
 int N, M;
 int i, j;

 scanf("%d%d", &N, &M);

 double **mas = (double**)malloc(N*sizeof(double*));
 for (i = 0; i < N; i++)
  mas[i] = (double*)malloc(M*sizeof(double));

 srand(time(NULL));
 for (i = 0; i < N; i++)
  for (j = 0; j < M; j++)
   mas[i][j] = rand() % 10;

 printf("Matrix:\n");
 for (i = 0; i < N; i++)
 {
  for (j = 0; j < M; j++)
   printf("%2f", mas[i][j]);
  printf("\n");
 }

 double **trans = transpM(mas, N, M);

 printf("Transp_Matrix:\n");
 for (i = 0; i < M; i++)
 {
  for (j = 0; j < N; j++)
   printf("%2f", trans[i][j]);
  printf("\n");
 }

 if (M == N)
 {
  double **invert = invertM(mas, N);

  printf("Invert_Matrix:\n");
  for (i = 0; i < N; i++)
  {
   for (j = 0; j < N; j++)
    printf("%2f", invert[i][j]);
   printf("\n");
  }

  for (i = 0; i < N; i++)
   free(invert[i]);
  free(invert);
 }

 for (i = 0; i < N; i++)
  free(mas[i]);
 free(mas);

 for (i = 0; i < M; i++)
  free(trans[i]);
 free(trans);

 return 0;
}

double **transpM(double **mas, int N, int M)
{
 int i, j;
 double **result = (double**)malloc(M*sizeof(double*));
 for (i = 0; i < M; i++)
  result[i] = (double*)malloc(N*sizeof(double));

 for (i = 0; i < N; i++)
  for (j = 0; j < M; j++)
   result[j][i] = mas[i][j];

 return result;
}

double **invertM(double **mas, int N)
{
 int i, j, k;
 double **result = (double**)malloc(N*sizeof(double*));
 for (i = 0; i < N; i++)
  result[i] = (double*)malloc(N*sizeof(double));

 double **tmp_mas = (double**)malloc(N*sizeof(double*));
 for (i = 0; i < N; i++)
  tmp_mas[i] = (double*)malloc(N*sizeof(double));

 for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
   tmp_mas[i][j] = mas[i][j];

 for (i = 0; i < N; i++)
  for (j = N; j < 2*N; j++)
  {
   if (i+N == j)
    tmp_mas[i][j] = 1;
   else
    tmp_mas[i][j] = 0;
  }

 for (i = 0; i < N; i++)
 {
  if (tmp_mas[i][i] == 0)
   for (j = i+1; j < N; j++)
   {
    if (tmp_mas[j][i] == 1)
    {
     for (k = 0; k < 2*N; k++)
     {
      double c = tmp_mas[j][k];
      tmp_mas[j][k] = tmp_mas[i][k];
      tmp_mas[i][k] = c;
     }
     break;
    }
   }
  for (k = i+1; k < N; k++)
  {
   if (tmp_mas[k][i] == 1)
   {
    for (j = 0; j < 2*N; j++)
    {
     tmp_mas[k][j] ^= tmp_mas[i][j];
    }
   }
  }
 }
 for (i = N-1; i >= 0; i--)
 {
  for (k = i-1; k >= 0; k--)
  {
   if (tmp_mas[k][i] == 1)
   {
    for (j = 0; j < 2*N; j++)
     tmp_mas[k][j]^= tmp_mas[i][j];
   }
  }
 }

 for (i = 0; i < N; i++)
  for (j = 0, k = N; j < N; j++, k++)
   result[i][j]=tmp_mas[i][k];

 for (i = 0; i < N; i++)
  free(tmp_mas[i]);
 free(tmp_mas);

 return result;
}
