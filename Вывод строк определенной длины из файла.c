#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#define size 101
int main(void)
{
  FILE *f;
  char filename[size], s[size];
  scanf("%s", filename);
  f = fopen(filename, "r");
  while (fgets(s, size, f) != NULL)
    if (strlen(s) > 20)
      printf("%s", s);
  fclose(f);
  return 0;
}