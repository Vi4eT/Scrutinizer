#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int main(void)
{
  double n, i = 2, k = 0, root, prove = 1, fprove;
  int a[100], j = 0, p = 0;
  scanf("%lf", &n);
  fprove = n;
  root = sqrt(n);
  if (n == 0)
    printf("%.0lf", n);
  else if (n == i || n == 1)
    printf("%.0lf^1", n);
  else
  {
    while (i <= root)
    {
      if ((int)n % (int)i == 0)
      {
        k++;
        if (n == i)
        {
          printf("%.0lf^%.0lf", n, k);
          prove *= pow(n, k);
          break;
        }
        else
          n /= i;
      }
      else
      {
        if (k == 0)
          i++, k = 0;
        else
        {
          printf("%.0lf^%.0lf * ", i, k);
          prove *= pow(i, k);
          i++, k = 0;
          if (n > root)
          {
            a[j] = (int)n;
            prove *= a[j];
            j++;
          }
        }
      }
    }
    if (prove == 1)
      printf("%.0lf^1", n);
    else
    {
      while (prove != fprove)
      {
        prove /= a[p];
        prove = floor(prove + 0.5);
        a[p] = -1;
        p++;
      }
      for (j -= 1; j > -1; j--)
      {
        if ((j == 0 && a[j] > -1) || (j > 0 && a[j] > a[j - 1] && a[j] > -1))
          printf("%d^1", a[j]);
        else if (a[j] > -1)
          printf("%d^1 * ", a[j]);
      }
    }
  }
  return 0;
}