#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int digits(int n)
{
  int tsif = 0;
  if (n / 10 == 0)
    return 1;
  else
  {
    while (n > 0)
    {
      n = n / 10;
      tsif++;
    }
    return tsif;
  }
}
int vmasa(int *a, int n, int m)
{
  int i, d1, sdvig;
  d1 = digits(n);
  for (i = 0; i < d1; i++)
  {
    a[i] = n % 10;
    n = n / 10;
  }
  sdvig = digits(m) - d1;
  if (sdvig < 0)
    sdvig = 0;
  i += sdvig;
  for (i = 10 - i; i > 0; i--)
    printf("  ");
  for (i = d1 - 1; i > -1; i--)
    printf("%d ", a[i]);
  printf("\n");
  return *a;
}
int vmasb(int *b, int m, int n)
{
  int i, d2, sdvig;
  d2 = digits(m);
  for (i = 0; i < d2; i++)
  {
    b[i] = m % 10;
    m = m / 10;
  }
  sdvig = d2 - digits(n);
  if (sdvig < 0)
    sdvig = 0;
  i += sdvig;
  for (i = 10 - i; i > 0; i--)
    printf("  ");
  for (i = d2 - 1; i > -1; i--)
    printf("%d ", b[i]);
  printf("\n");
  return *b;
}
int izcvint(int *c)
{
  int i, t = 1, p, r = 0, d3 = 0;
  for (i = 0; i < 10; i++)
  {
    if (c[i] > -1)
      d3++;
  }
  for (i = 0; i < d3; i++)
  {
    p = c[i] * t;
    t *= 10;
    r += p;
  }
  return r;
}
int sum(int *a, int *b, int *c, int d1)
{
  int i, d3 = 0, e, d = 0;
  for (i = 0; i < d1; i++)
  {
    if (b[i] < 0)
      b[i] = 0;
    e = d;
    c[i] = a[i] + b[i] + e;
    d = c[i] / 10;
    d3++;
    if (a[i + 1] < 0 && c[i] > 9)
    {
      c[i + 1] = 1;
      c[i] = c[i] % 10;
      d3++, i++;
      for (; i < d1; i++)
      {
        c[i] += b[i];
        if (c[i] > 9)
        {
          c[i + 1] = 1;
          c[i] = c[i] % 10;
        }
        else
          break;
      }
    }
    if (b[i + 1] < 0 && c[i] > 9)
    {
      c[i + 1] = 1;
      c[i] = c[i] % 10;
    }
    if (c[i] > 9)
    {
      c[i + 1]++;
      c[i] = c[i] % 10;
    }
  }
  for (i = 10 - d3; i > 0; i--)
    printf("  ");
  for (i = d3 - 1; i > -1; i--)
    printf("%d ", c[i]);
  printf("\n");
  return *c;
}
int main(void)
{
  int a[10], b[10], c[10], n, m, t1, t2, result;
  scanf("%d", &n);
  scanf("%d", &m);
  if (n > m)
    t1 = n, t2 = m;
  else
    t1 = m, t2 = n;
  vmasa(a, t1, t2);
  vmasb(b, t2, t1);
  sum(a, b, c, digits(t1));
  result = izcvint(c);
  return 0;
}