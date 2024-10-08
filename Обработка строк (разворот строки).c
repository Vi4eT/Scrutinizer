#pragma warning(disable : 4996)
#include <stdio.h>
#define M 100
void reverse(char *str)
{
  if (*str != '\0')
  {
    reverse(str + 1);
    putchar(*str);
  }
}
int main(void)
{
  char str[M];
  gets(str);
  reverse(str);
  return 0;
}