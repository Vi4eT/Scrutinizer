#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int main(void)
{
  int a, i, x, y, z;
  scanf("%d", &x);
  a = 0;
  y = 0;
  z = 0;
  if (x > 0)
    z = 1;
  for (i = 1; i < 2; i++)
  {
    a = y + z;
  }
  for (i = 1; i < x; i++)
  {
    a = y + z;
    if (y < z)
      y = a;
    else
      z = a;
  }
  printf("%d", a);
  return 0;
}