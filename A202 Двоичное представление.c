#pragma warning(disable : 4996)
#include <stdio.h>
int main(void)
{
  int a[100], x, i = 0;
  scanf("%d", &x);
  if (x == 0)
    printf("0");
  while (x != 0)
  {
    a[i] = x % 2;
    x /= 2;
    i++;
  }
  for (i -= 1; i > -1; i--)
    printf("%d", a[i]);
  return 0;
}