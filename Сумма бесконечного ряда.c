#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
double fun_F(double x)
{
  int i = 0;
  double y, v, s;
  y = x;
  s = x;
  do
  {
    v = ((x * x) * (2 * i + 1) * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
    y *= v;
    s += y;
    i++;
  } while (s + y != s);
  return s;
}
double fun_G(double x)
{
  return asin(x);
}
double mod(double x)
{
  double F, G;
  F = fun_F(x);
  G = fun_G(x);
  return fabs(F - G);
}
void print(double a, double b, int n)
{
  double h, x = a;
  int i;
  if (a > b)
  {
    h = a;
    a = b;
    b = h;
  }
  h = (b - a) / (n - 1);
  printf("+---+-------+-------+-------+-------------+\n");
  printf("| k |   x   |  f(x) |  g(x) | |f(x)-g(x)| |\n");
  printf("+---+-------+-------+-------+-------------+\n");
  for (i = 0; i < n; i++)
  {
    printf("| %02d|%7.4lf|%7.4lf|%7.4lf|%e|\n", i + 1, x, fun_F(x), fun_G(x), mod(x));
    x += h;
  }
  printf("+---+-------+-------+-------+-------------+\n");
}
int main(void)
{
  double a, b;
  int n;
  scanf("%lf %lf %i", &a, &b, &n);
  print(a, b, n);
  return 0;
}