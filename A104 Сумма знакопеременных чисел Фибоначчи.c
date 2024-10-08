#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int main(void)
{
  int a, i, x, y, z, n = 0;
  scanf("%d", &x);
  a = 0;
  y = 0;
  z = 0;
  if (x > 0)
    z = 1;
  if (a == 0)
    printf("%d", a);
  for (i = 1; i < 2; i++)
  {
    a = y + z;
    if (i % 2 == 0)
    {
      printf("%d", -a);
      n -= a;
    }
    else if (a != 0 && x != 1)
    {
      printf("+%d", a);
      n += a;
    }
  }
  for (i = 2; i < x; i++)
  {
    a = y + z;
    if (i % 2 == 0)
    {
      printf("%d", -a);
      n -= a;
    }
    else
    {
      printf("+%d", a);
      n += a;
    }
    if (y < z)
      y = a;
    else
      z = a;
  }
  printf("=%d", n);
  return 0;
}