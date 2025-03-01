#include "find_roots.c"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void test_find_roots_1() {
  double a = 1;
  double b = 0;
  double c = -1;
  double *res = find_roots(a, b, c);
  assert(fabs(res[0] - 2) < 10E-7 && fabs(res[1] + 1) < 10E-7 &&
         fabs(res[2] - 1) < 10E-7);
}
void test_find_roots_2() {
  double a = 1;
  double b = 0;
  double c = 0;
  double *res = find_roots(a, b, c);
  assert(fabs(res[0] - 1) < 10E-7 && fabs(res[1]) < 10E-7);
}
void test_find_roots_3() {
  double a = 1;
  double b = 0;
  double c = 1;
  double *res = find_roots(a, b, c);
  assert(fabs(res[0]) < 10E-7);
}
void test_find_roots_4() {
  double a = 1;
  double b = 0;
  double c = -1e-7;
  double *res = find_roots(a, b, c);
  assert(fabs(res[0] - 2) < 10E-7 && fabs(res[1] + 3e-4) < 10E-5 &&
         fabs(res[2] - 3e-4) < 10E-5);
}
void test_find_roots_5() {
  double a = 1;
  double b = -1e+10;
  double c = -1;
  double *res = find_roots(a, b, c);
  assert(fabs(res[0] - 2) < 10E-7 && fabs(res[1] + 1e-10) < 10E-11 &&
         fabs(res[2] - 1e+10) < 10E-11);
}
void test_find_roots_6() {
  double a = 1;
  double b = 0;
  double c = -1e-8;
  double *res = find_roots(a, b, c);
  assert(fabs(res[0] - 1) < 10E-7 && fabs(res[1]) < 10E-7);
}

int main() {
  test_find_roots_1();
  test_find_roots_2();
  test_find_roots_3();
  test_find_roots_4();
  test_find_roots_5();
  // test_find_roots_6();

  return 0;
}
