#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
double random(double arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    arr[i] = rand();
  return *arr;
}
double fill(double arr[], int n, double a, double b)
{
  double x;
  int i;
  for (i = 0; i < n; i++)
  {
    x = a + arr[i] / (RAND_MAX + 1) * (b - a);
    arr[i] = x;
  }
  return *arr;
}
void print(double arr[], int n)
{
  int i;
  printf("{");
  for (i = 0; i < n - 1; i++)
    printf("%.3lf, ", arr[i]);
  printf("%.3lf", arr[i]);
  printf("}");
  printf("\n");
}
void printhistline(double n, int width)
{
  int i;
  for (i = 0; i < n; i++)
    printf("#");
  for (; i < width; i++)
    printf(".");
  printf("\n");
}
void printhist(int hist[], int stlb, int width, double scale)
{
  int i;
  double n;
  for (i = 0; i < stlb; i++)
  {
    n = hist[i] * scale;
    printhistline((int)(n + 0.5), width);
  }
}
int buildhist(double arr[], int hist[], int n, int stlb, double a, double b)
{
  int i, j;
  for (j = 0; j < n; j++)
  {
    i = (int)fabs((arr[j] - a) / (b - a) * stlb);
    hist[i]++;
  }
  return *hist;
}
void printverthist(int hist[], int stlb, int width, double scale)
{
  int i, j, mhist = hist[0];
  double n;
  for (i = 0; i < stlb; i++)
  {
    if (mhist < hist[i])
      mhist = hist[i];
  }
  scale = (double)width / mhist;
  for (j = 0; j < width; j++)
  {
    for (i = 0; i < stlb; i++)
    {
      n = hist[i] * scale;
      if ((int)(n + 0.5) > width - 1 - j)
        printf("#");
      else
        printf(".");
    }
    printf("\n");
  }
}
double randomskewed(double arr[], int n, double a, double b)
{
  double y;
  int i;
  for (i = 0; i < n; i++)
  {
    y = a + sqrt(arr[i] / (RAND_MAX + 1)) * (b - a);
    arr[i] = y;
  }
  return *arr;
}
int main(void)
{
  double *arr, a = 0.2, b = 0.6, scale;
  int *hist, n = 10, stlb, width = 20;
  setlocale(LC_CTYPE, "Russian");
  srand((unsigned)time(0));
  arr = (double *)malloc(n * sizeof(double));
  random(arr, n);
  fill(arr, n, a, b);
  printf("Тест ГСЧ: ");
  print(arr, n);
  free(arr);
  printf("Введите кол-во чисел, кол-во столбцов, нижнюю и верхнюю границы: ");
  scanf("%d %d %lf %lf", &n, &stlb, &a, &b);
  arr = (double *)malloc(n * sizeof(double));
  hist = (int *)calloc(stlb, stlb * sizeof(int));
  random(arr, n);
  fill(arr, n, a, b);
  buildhist(arr, hist, n, stlb, a, b);
  printf("Равномерное распределение:\n");
  scale = 2 * width / (double)n;
  printhist(hist, stlb, width, scale);
  printf("Вертикальная гистограмма равномерного распределения:\n");
  printverthist(hist, stlb, width, scale);
  free(hist);
  random(arr, n);
  randomskewed(arr, n, a, b);
  hist = (int *)calloc(stlb, stlb * sizeof(int));
  buildhist(arr, hist, n, stlb, a, b);
  printf("Неравномерное распределение:\n");
  printhist(hist, stlb, width, scale);
  printf("Вертикальная гистограмма неравномерного распределения:\n");
  printverthist(hist, stlb, width, scale);
  free(arr);
  free(hist);
  return 0;
}