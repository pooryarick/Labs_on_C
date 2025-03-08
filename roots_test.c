#include "find_roots.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void test_find_roots_1() {
  double e = 1E-7;
  double a = 1;
  double b = 0;
  double c = -1;
  double *res = find_roots(a, b, c, e);
  assert(fabs(res[0] - 2) < e && fabs(res[1] + 1) < e && fabs(res[2] - 1) < e);
}
void test_find_roots_2() {
  double e = 1E-7;
  double a = 1;
  double b = 0;
  double c = 0;
  double *res = find_roots(a, b, c, e);
  assert(fabs(res[0] - 1) < e && fabs(res[1]) < e);
}
void test_find_roots_3() {
  double e = 1E-7;
  double a = 1;
  double b = 0;
  double c = 1;
  double *res = find_roots(a, b, c, e);
  assert(fabs(res[0]) < e);
}
void test_find_roots_4() {
  double e = 1E-4;
  double a = 1;
  double b = 0;
  double c = -1E-7;
  double *res = find_roots(a, b, c, e);
  assert(fabs(res[0] - 2) < e && fabs(res[1] + 3e-4) < e &&
         fabs(res[2] - 3e-4) < e);
}
void test_find_roots_5() {
  double e = 1E-11;
  double a = 1;
  double b = -1E+10;
  double c = -1;
  double *res = find_roots(a, b, c, e);
  assert(fabs(res[0] - 2) < e && fabs(res[1] + 1e-10) < e &&
         fabs(res[2] - 1e+10) < e);
}
void test_find_roots_6() {
  double e = 1E-7;
  double a = 1;
  double b = 0;
  double c = -1E-8;
  double *res = find_roots(a, b, c, e);
  assert(fabs(res[0] - 1) < e && fabs(res[1]) < e);
}

int main() {
  test_find_roots_1();
  test_find_roots_2();
  test_find_roots_3();
  test_find_roots_4();
  test_find_roots_5();
  test_find_roots_6();
  return 0;
}
