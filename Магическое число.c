#include <stdio.h>
#define N 20
int main(void)
{
  int i, b, c = 0, a[N];
  a[0] = 2;
  for (i = 1; i < N; i++)
  {
    b = a[i - 1] * 2 + c;
    a[i] = b % 10;
    c = b / 10;
    if (b == 2 && c == 0)
      break;
  }
  for (; i > 0; i--)
    printf("%d", a[i]);
  return 0;
}