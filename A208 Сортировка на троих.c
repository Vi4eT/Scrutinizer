#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int n, i, zeros = 0, ones = 0, twos = 0;
  short *a;
  scanf("%d", &n);
  a = (short *)malloc(n * sizeof(short));
  for (i = 0; i < n; i++)
    scanf("%hu", &a[i]);
  for (i = 0; i < n; i++)
  {
    if (a[i] == 0)
      zeros++;
    else if (a[i] == 1)
      ones++;
    else
      twos++;
  }
  for (i = 0; i < zeros; i++)
    printf("0 ");
  for (i = 0; i < ones; i++)
    printf("1 ");
  for (i = 0; i < twos; i++)
    printf("2 ");
  free(a);
  return 0;
}