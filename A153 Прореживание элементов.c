#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int *a, n, k, i;
  scanf("%d %d", &n, &k);
  a = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    if (i % k == 0)
      printf("%d ", a[i]);
  }
  free(a);
  return 0;
}