#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
int main(void)
{
  int i, check;
  char s[101];
  gets(s);
  if (strlen(s) != 0)
  {
    for (i = 0; s[i] != 0; i++)
    {
      if ((s[i - 1] >= 'a' && s[i - 1] <= 'z') || (s[i - 1] >= 'A' && s[i - 1] <= 'Z'))
        check = 1;
      else
        check = 0;
      if ((s[i] >= 'a' && s[i] <= 'z') && check == 0)
        s[i] -= 32;
      if ((s[i] >= 'A' && s[i] <= 'Z') && check == 1)
        s[i] += 32;
    }
  }
  puts(s);
  return 0;
}