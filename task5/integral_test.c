#include "integral.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void integral_test_1() {
  double a = 2;
  double b = 3;
  unsigned int n = 100000;
  assert(fabs(integral(sinus, a, b, n) - 0.573846) < 10e-6);
}
void integral_test_2() {
  double a = 3;
  double b = 6;
  unsigned int n = 100000;
  assert(fabs(integral(parabola, a, b, n) - 63) < 10e-6);
}
void integral_test_3() {
  double a = 3;
  double b = 6;
  unsigned int n = 100000;
  assert(fabs(integral(cosinus, a, b, n) + 0.420536) < 10e-6);
}
void integral_test_4() {
  double a = 3;
  double b = 6;
  unsigned int n = 100000;
  assert(fabs(integral(logn, a, b, n) - 4.45472) < 10e-5);
}

int main() {
  integral_test_1();
  integral_test_2();
  integral_test_3();
  integral_test_4();
  return 0;
}
