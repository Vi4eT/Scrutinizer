#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
int main(void)
{
  double a, b, c, d, x, x1 = 0, x2 = 0;
  scanf("%hf %hf %hf", &a, &b, &c);
  if (a == 0 && b == 0 && c == 0)
    printf("ALL");
  else if (a == 0 && b == 0 && c != 0)
    printf("NONE");
  else if (a == 0)
  {
    x1 = -c / b;
    if (c == 0)
      x1 = 0;
    printf("%.4f", x1);
  }
  else
  {
    d = pow(b, 2) - 4 * a * c;
    if (d < 0)
      printf("NONE");
    else if (d == 0)
    {
      x1 = -b / (2 * a);
      if (b == 0 && c == 0)
        x1 = 0;
      printf("%.4f", x1);
    }
    else
    {
      x1 = (-b + sqrt(d)) / (2 * a);
      x2 = (-b - sqrt(d)) / (2 * a);
      if (x1 < x2)
      {
        x = x2, x2 = x1, x1 = x;
        printf("%.4f %.4f", x1, x2);
      }
      else if (x1 == x2)
        printf("%.4f", x1);
      else
        printf("%.4f %.4f", x1, x2);
    }
  }
  return 0;
}