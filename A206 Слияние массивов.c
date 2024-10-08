#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int n, m, *a, *b, i, j;
  scanf("%d %d", &n, &m);
  a = (int *)malloc(n * sizeof(int));
  b = (int *)malloc(m * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (i = 0; i < m; i++)
    scanf("%d", &b[i]);
  for (i = 0, j = 0; i < n && j < m;)
  {
    if (a[i] < b[j])
    {
      printf("%d ", a[i]);
      i++;
    }
    else
    {
      printf("%d ", b[j]);
      j++;
    }
  }
  if (i == n)
    for (; j < m; j++)
      printf("%d ", b[j]);
  else
    for (; i < n; i++)
      printf("%d ", a[i]);
  free(a);
  free(b);
  return 0;
}