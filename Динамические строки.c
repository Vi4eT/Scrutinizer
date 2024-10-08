#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
char *readline(void)
{
  int check = 0, i = 1;
  char *str, *str1, c = 0;
  str = (char *)malloc(10);
  str1 = (char *)malloc(1);
  free(str1);
  if (str == NULL)
    printf("error 1");
  while ((c = (char)getchar()) != '\n')
  {
    if (check == 0)
    {
      str[i - 1] = c;
      if (i % 10 == 9)
      {
        str1 = (char *)realloc(str, i + 11);
        if (str1 == NULL)
          printf("error 2");
        check = 1;
      }
    }
    else
    {
      str1[i - 1] = c;
      if (i % 10 == 9)
      {
        str = (char *)realloc(str1, i + 11);
        if (str == NULL)
          printf("error 3");
        check = 0;
      }
    }
    i++;
  }
  if (check == 0)
  {
    str[i - 1] = '\0';
    return str;
  }
  else
  {
    str1[i - 1] = '\0';
    return str1;
  }
}
char *extractletters(char const *s)
{
  char *r;
  int i, j;
  for (i = 0; s[i] != '\0'; i++)
    ;
  r = (char *)malloc(i + 1);
  for (i = 0, j = 0; s[i] != '\0'; i++)
  {
    if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9')))
    {
      r[j] = s[i];
      j++;
    }
  }
  r[j] = '\0';
  return r;
}
void print(char const *r)
{
  int i;
  for (i = 0; r[i] != '\0'; i++)
  {
    if (r[i + 1] == '\0')
      printf("%c", r[i]);
    else
      printf("%c, ", r[i]);
  }
  printf("\n");
}
int main(void)
{
  char *s, *r;
  setlocale(LC_CTYPE, "Russian");
  do
  {
    printf("Введите строку: ");
    s = readline();
    r = extractletters(s);
    printf("Результат     : ");
    print(r);
  } while (s[0] != 0);
  free(s);
  free(r);
  return 0;
}