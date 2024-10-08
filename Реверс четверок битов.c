#pragma warning(disable : 4996)
#include <stdio.h>
typedef unsigned long long int_t;
typedef unsigned long long max;
void output(max x)
{
  int i;
  printf("%*llu = ", 26, x);
  printf("0x%016llX = ", x);
  for (i = 8 * sizeof(x) - 1; i > -1; i--)
    printf("%u", x >> i & 1);
  printf("\n");
}
int_t reverse4(int_t x)
{
  int_t xcopy = x, xcopy2, temp, mask;
  int i, sdvig = 2 * sizeof(x) - 1, sdvig1;
  for (i = 0; i < sizeof(x); i++)
  {
    temp = xcopy & 15;
    xcopy >>= 4;
    mask = 15;
    mask <<= 4 * sdvig;
    x = x & ~mask;
    temp <<= 4 * sdvig;
    x |= temp;
    sdvig--;
  }
  sdvig1 = sdvig;
  xcopy2 = xcopy;
  for (i = 0; i < sizeof(x); i++)
  {
    temp = xcopy & 15;
    xcopy >>= 4;
    mask = 15;
    mask <<= 4 * sdvig1;
    xcopy2 = xcopy2 & ~mask;
    temp <<= 4 * sdvig1;
    xcopy2 |= temp;
    sdvig1--;
  }
  for (i = sizeof(x); i > 0; i--)
  {
    mask = 15;
    mask <<= 4 * sdvig;
    x = x & ~mask;
    sdvig--;
  }
  x |= xcopy2;
  return x;
}
int_t main(void)
{
  max x;
  do
  {
    scanf("%llu", &x);
    output((int_t)x);
    x = reverse4((int_t)x);
    output(x);
  } while (x != 0);
  return 0;
}