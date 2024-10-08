#pragma warning(disable : 4996)
#include <stdio.h>
#define M 100
char *word = "wicked";
void replace(char *str)
{
  int i, j = 0, x, a = 0;
  for (i = 0; i < M; i++)
  {
    if (str[i] == word[j])
    {
      x = i;
      while (str[i] == word[j] && word[j] != '\0')
      {
        i++, j++;
        if (str[i] == word[j])
          a = 1;
        else if (word[j] != '\0')
          a = 0, j = 0;
        else
          j = 0;
      }
    }
    if (a == 1)
    {
      str[x] = 'g';
      str[x + 1] = 'o';
      str[x + 2] = 'o';
      str[x + 3] = 'd';
      for (; x + 6 < M; x++)
      {
        str[x + 4] = str[x + 6];
        if (str[x + 6] == 0)
          break;
      }
      i -= 2;
      a = 0;
    }
  }
}
int main(void)
{
  char str[M];
  gets(str);
  replace(str);
  printf("%s\n", str);
  return 0;
}