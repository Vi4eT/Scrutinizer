#pragma warning(disable : 4996)
#include <stdio.h>
int main(void)
{
  int a[100], t, x, b, c, i = 0;
  scanf("%d %d", &b, &c);
  scanf("%c", &x);
  if (x == 0 || b == c)
    printf("%d", x);
  else
  {
    if (b != 10)
    {
    }
    while (x)
    {
      a[i] = x % c;
      x /= c;
      i++;
    }
    for (i -= 1; i > -1; i--)
    {
      if (a[i] < 10)
        printf("%c", a[i] + 48);
      else
        printf("%c", a[i] + 55);
    }
  }
  return 0;
}