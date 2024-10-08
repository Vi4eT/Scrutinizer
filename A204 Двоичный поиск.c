#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int search(int a[], int n, int x)
{
  int f = 0, l = n, m;
  if (n == 0 || a[0] > x || a[n - 1] < x)
    return printf("0");
  while (f < l)
  {
    m = f + (l - f) / 2;
    if (x <= a[m])
      l = m;
    else
      f = m + 1;
  }
  if (a[l] == x)
    return printf("1");
  else
    return printf("0");
}
int main(void)
{
  int n, m, *a, *b, i;
  scanf("%d %d", &n, &m);
  a = (int *)malloc(n * sizeof(int));
  b = (int *)malloc(m * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (i = 0; i < m; i++)
    scanf("%d", &b[i]);
  for (i = 0; i < m; i++)
    search(a, n, b[i]);
  free(a);
  free(b);
  return 0;
}