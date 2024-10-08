#pragma warning(disable : 4996)
#include <stdio.h>
int delcomm(char *s, char *r)
{
  int opened = 0;
  while (*s)
  {
    if (*s == '/' && *(s + 1) == '*')
    {
      opened++;
      s += 2;
    }
    else if (*s == '*' && *(s + 1) == '/')
    {
      if (opened)
        opened--;
      else
        return 1;
      s += 2;
    }
    else if (*s == '/' && *(s + 1) == '/' && !opened)
      break;
    else if (opened)
      s++;
    else
      *r++ = *s++;
  }
  *r = '\0';
  if (opened)
    return 1;
  return 0;
}
int main(void)
{
  char str[101], res[101];
  gets_s(str, 101);
  if (delcomm(str, res))
    puts("ERROR");
  else
    puts(res);
  return 0;
}