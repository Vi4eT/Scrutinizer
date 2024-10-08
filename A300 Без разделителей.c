#pragma warning(disable : 4996)
#include <stdio.h>
int main(void)
{
  char str[101];
  int i;
  gets(str);
  for (i = 0; str[i] != '\0'; i++)
  {
    if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= '0') && (str[i] <= '9')))
      printf("%c", str[i]);
  }
  return 0;
}