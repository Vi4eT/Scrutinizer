#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int main(void)
{
  int i, x;
  scanf("%d", &x);
  for (i = 1; i < x; i++)
  {
    printf("%d+", i);
  }
  printf("%d", x);
  printf("=%d\n", (i * (i + 1)) / 2);
  return 0;
}