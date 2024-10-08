#pragma warning(disable : 4996)
#include <stdio.h>
int main(void)
{
  int a, b, c;
  scanf("%d %d", &a, &b);
  while (b)
  {
    c = a % b;
    a = b;
    b = c;
  }
  printf("%d", a);
  return 0;
}