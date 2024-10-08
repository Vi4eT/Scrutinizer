#pragma warning(disable : 4996)
#include <stdio.h>
int main(void)
{
  int a[201][201], n, i, j, ind = 0, ncopy, c = 1, d = 0;
  scanf("%d", &n);
  for (ncopy = n, i = 0; i < 2 * n + 1; i++, ncopy--)
  {
    for (j = 0; j < 2 * n + 1; j++)
    {
      if (i <= n)
        a[i][j] = i;
      else
      {
        a[i][j] = n - c;
        ind = 1;
      }
    }
    if (ind == 1)
      c++;
  }
  for (j = 0; j < (2 * n + 1) / 2; j++, d++)
    for (i = d; i < 2 * n - d; i++)
      a[i][j] = d;
  for (d = 0, j = 2 * n; j > d; j--, d++)
    for (i = 2 * n - d; i > d; i--)
      a[i][j] = d;
  for (i = 0; i < 2 * n + 1; i++)
  {
    for (j = 0; j < 2 * n + 1; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}