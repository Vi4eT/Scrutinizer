#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int *a, n, m, i;
  scanf("%d %d", &n, &m);
  a = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  if (m == 0 || n == m)
  {
    for (i = 0; i < n; i++)
      printf("%d ", a[i]);
  }
  else
  {
    for (i = m; i < n; i++)
      printf("%d ", a[i]);
    for (i = 0; i < m; i++)
      printf("%d ", a[i]);
  }
  free(a);
  return 0;
}