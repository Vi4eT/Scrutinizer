#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define N 24
float random(float arr[], int l)
{
  int i;
  for (i = 0; i < l; i++)
    arr[i] = (float)rand();
  return *arr;
}
float fill(float arr[], int l)
{
  int i;
  float x;
  for (i = 0; i < l; i++)
  {
    x = (float)arr[i] / (RAND_MAX + 1) * 100;
    arr[i] = x;
  }
  return *arr;
}
void print(float arr[], int l)
{
  int i;
  printf("{");
  for (i = 0; i < l - 1; i++)
    printf("%.1f, ", arr[i]);
  printf("%.1f}", arr[i]);
  printf("\n");
}
void writetext(char const *filename, float arr[], int l)
{
  int i;
  FILE *f = fopen(filename, "w");
  for (i = 0; i < l; i++)
    fprintf(f, "%.1f ", arr[i]);
  fclose(f);
}
void writebinary(char const *filename, float arr[], int l)
{
  FILE *f = fopen(filename, "wb");
  fwrite(arr, l, 1, f);
  fclose(f);
}
void dumpfile(char const *filename)
{
  int c, i = 0, j = 0, k, f;
  unsigned char arr[16];
  FILE *fl = fopen(filename, "rb");
  while ((c = fgetc(fl)) != EOF)
  {
    if (i % 16 == 0)
    {
      printf("%08X: ", i);
      j = 0;
    }
    k = i;
    printf("%02X ", c);
    arr[j] = c;
    j++;
    i++;
    if (j < 16)
      continue;
    printf(" ");
    for (j = 0; c != EOF && j < 16; j++, k++)
    {
      if (isprint(arr[j]) == 0)
        printf(".");
      else
        printf("%c", arr[j]);
    }
    printf("\n");
    if (c == EOF)
      break;
  }
  if (j < 16)
  {
    for (f = 48; f > j * 3; f--)
      printf(" ");
    printf(" ");
    for (i = 0; i < j; i++)
    {
      if (isprint(arr[i]) == 0)
        printf(".");
      else
        printf("%c", arr[i]);
    }
    printf("\n");
  }
  fclose(fl);
}
int main(void)
{
  float a[N];
  srand((unsigned)time(0));
  random(a, N);
  fill(a, N);
  printf("float array: ");
  print(a, N);
  writetext("array.txt", a, N);
  writebinary("array.bin", a, N);
  printf("array.txt dump:\n");
  dumpfile("array.txt");
  printf("array.bin dump:\n");
  dumpfile("array.bin");
  return 0;
}