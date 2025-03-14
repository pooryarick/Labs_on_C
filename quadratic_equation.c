#include "quadratic_equation.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *find_roots(double a, double b, double c, double e, double discr_acc) {
  double *p;
  int size;
  if (fabs(a) < e) {
    printf("Can't find roots, a is 0 or extremely little\n");
    exit(-1);
  } else {
    b = b / a;
    c = c / a;
    double d = b * b - 4 * c;
    int sign;
    if (b < -e) {
      sign = -1;
    } else {
      sign = 1;
    }
    if (d >= discr_acc) {
      p = malloc(3 * sizeof(double));
      p[0] = 2;
      p[1] = (-b - sign * sqrt(d)) / 2;
      p[2] = c / p[1];
      if (p[2] < p[1]) {
        double s = p[2];
        p[2] = p[1];
        p[1] = s;
      }
      if (fabs(p[1]) < e) {
        p[1] = 0;
      }
      if (fabs(p[2]) < e) {
        p[2] = 0;
      }

    } else if (fabs(d) < discr_acc) {
      p = malloc(2 * sizeof(double));
      p[0] = 1;
      p[1] = (-b) / 2;
      if (fabs(p[1]) < e) {
        p[1] = 0;
      }
    } else {
      p = malloc(sizeof(double));
      p[0] = 0;
    }
  }
  return p;
}
