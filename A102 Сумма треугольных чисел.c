#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int main(void)
{
  int a, i, x, y, z;
  scanf("%d", &x);
  a = 0;
  for (i = 1; i <= x; i++)
  {
    y = (i * (i + 1)) / 2;
    z = +y;
    if (i < x)
      printf("%d+", z);
    else
      printf("%d", z);
    a = a + z;
  }
  printf("=%d", a);
  return 0;
}