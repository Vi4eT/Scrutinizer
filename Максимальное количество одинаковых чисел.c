/*input.txt
4 4
2 2 2 3
2 4 4 4
2 4 1 0
2 4 9 3*/
#pragma warning(disable : 4996)
#include <stdio.h>
#define size 100
int main(void)
{
  FILE *f;
  f = fopen("input.txt", "r");
  int lines, columns, i, j, result = 0, temp = 0;
  fscanf(f, "%d %d", &lines, &columns);
  int arr[size][size];
  for (i = 0; i < lines; i++)
    for (j = 0; j < columns; j++)
      fscanf(f, "%d ", &arr[i][j]);
  for (j = 0; j < columns; j++)
    for (i = 0; i < lines; i++)
    {
      for (int k = 0; k < lines; k++)
        if (arr[i][j] == arr[k][j])
          temp++;
      if (temp > result)
        result = temp;
      temp = 0;
    }
  printf("%d\n", result);
  fclose(f);
  return 0;
}