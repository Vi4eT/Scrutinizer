#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int *a, n, i, x = 0;
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  x = a[0];
  for (i = 1; i < n; i++)
  {
    if (x > a[i])
    {
      x = a[i];
    }
  }
  printf("%d ", x);
  free(a);
  return 0;
}