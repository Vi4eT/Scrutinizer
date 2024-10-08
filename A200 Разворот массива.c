#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int *a, n, i;
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (i = n - 1; i > -1; i--)
    printf("%d ", a[i]);
  free(a);
  return 0;
}