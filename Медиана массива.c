#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
void sort(int a[], int n)
{
  int i = 0, j = n - 1, t, m;
  m = a[n >> 1];
  do
  {
    while (a[i] < m)
      i++;
    while (a[j] > m)
      j--;
    if (i <= j)
    {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      j--;
    }
  } while (i <= j);
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  if (j > 0)
    sort(a, j);
  if (n > i)
    sort(a + i, n - i);
}
int main(void)
{
  int *a, n, i, k;
  scanf("%d", &n);
  a = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  if (n % 2 == 0)
    k = n / 2 - 1;
  else
    k = (n - 1) / 2;
  sort(a, n);
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  printf("%d", a[k]);
  return 0;
}