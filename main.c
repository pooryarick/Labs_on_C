#include "integral.h"
#include <stdio.h>

int main() {
  double a = 2;
  double b = 5;
  unsigned int n = 10000000;

  printf("%lf\n", integral(sinus, a, b, n));
  return 0;
}
