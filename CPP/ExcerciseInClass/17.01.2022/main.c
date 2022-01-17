#include <stdio.h>

int display(int i)
{
  printf("%d", i);

  return i;
}

double display(double d)
{
  printf("%lf", d);

  return d;
}

int main(void)
{
  int i = 4;
  double d = 32.5;

  display(i);
  display(d);

  return 0;
}

