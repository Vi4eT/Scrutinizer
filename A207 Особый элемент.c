#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int *a, n, sum = 0, s, i, j = 0;
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (i = 0; i < n; i++)
  {
    s = sum - a[i];
    if (a[i] == s)
      j++;
  }
  printf("%d", j);
  free(a);
  return 0;
}