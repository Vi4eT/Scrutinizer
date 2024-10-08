#pragma warning(disable : 4996)
#include <stdio.h>
int main(void)
{
  int n, i, k = 26;
  char s[101];
  scanf("%d\n", &n);
  gets(s);
  for (i = 0; s[i] != 0; i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      s[i] -= 65;
      s[i] = (s[i] - (char)n + (char)k) % (char)k;
      s[i] += 65;
    }
    if (s[i] >= 'a' && s[i] <= 'z')
    {
      s[i] -= 97;
      s[i] = (s[i] - (char)n + (char)k) % (char)k;
      s[i] += 97;
    }
  }
  puts(s);
  return 0;
}