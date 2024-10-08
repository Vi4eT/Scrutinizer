#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void)
{
  int *a, n, i, x = 0;
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    x += a[i];
  }
  printf("%d ", x);
  free(a);
  return 0;
}