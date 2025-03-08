#include "find_roots.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *find_roots(double a, double b, double c, double e) {
  double d = b * b - 4 * c;
  double discr_acc = 1E-7;
  double *p;
  int size;

  if (fabs(a) < e) {
    printf("Can't find roots, a is 0 or extremely little\n");
    exit(0);
  } else {
    b = b / a;
    c = c / a;
    int sign;
    if (b >= 0) {
      sign = 1;
    } else {
      sign = -1;
    }
    if (d >= discr_acc) {
      double x[3];
      x[0] = 2;
      x[1] = (-b - sign * sqrt(d)) / 2;
      x[2] = c / x[1];
      if (x[2] < x[1]) {
        double s = x[2];
        x[2] = x[1];
        x[1] = s;
      }
      if (fabs(x[1]) < e) {
        x[1] = 0;
      }
      if (fabs(x[2]) < e) {
        x[2] = 0;
      }
      p = x;
    } else if (0 <= d) {
      double x[1];
      x[0] = 1;
      x[1] = (-b) / 2;
      if (fabs(x[1]) < e) {
        x[1] = 0;
      }
      p = x;
    } else {
      double x[1];
      x[0] = 0;
      p = x;
    }
  }
  return p;
}
