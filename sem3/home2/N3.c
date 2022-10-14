#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void print(int mas[]);
void sdvig(int mas[], int num);

int main()
{

 int mas[N];
 int i;
 int num;

 srand(time(NULL));
 for (i = 0; i < N; i++)
  mas[i] = rand() % 10;

 printf("Enter the parameter:\n");
 scanf("%d", &num);

 printf("Old massive:\n");
 print(mas);

 sdvig(mas, num);

 printf("New massive:\n");
 print(mas);

 return 0;
}

void print(int mas[])
{
 int i;

 for (i = 0; i < N; i++)
  printf("%d ", mas[i]);

 printf("\n");
}

void sdvig(int mas[], int num)
{
 int p, i, j;
 for (i = 0; i < num % N; i++)
 {
  p = mas[N-1];

  for (j = N-1; j > 0; j--)
   mas[j] = mas[j-1];

  mas[0] = p;
 }
}
