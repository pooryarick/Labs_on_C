#include "integral.h"

double integral(double (*f)(double x), double a, double b, unsigned int n) {
  double res = 0;
  double deltx = (b - a) / n;
  for (int i = 0; i < n; i++) {
    double x1 = a + deltx * i;
    double x2 = x1 + deltx;
    res += (f(x1) + f(x2)) / 2 * (x2 - x1);
  }
  return res;
}
