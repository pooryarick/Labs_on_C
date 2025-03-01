#include "find_roots.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *find_roots(double a, double b, double c) {
  double d = b * b - 4 * a * c;
  double *p;
  int size;

  if (a == 0) {
    printf("Can't find roots\n");
    exit(0);
  } else {
    double d = b * b - 4 * a * c;
    int sign;
    if (b >= 0) {
      sign = 1;
    } else {
      sign = -1;
    }
    if (d > 0) {
      double x[3];
      x[0] = 2;
      // x[1] = (-b - sqrt(d)) / (2 * a);
      // x[2] = (-b + sqrt(d)) / (2 * a);
      x[1] = (-b - sign * sqrt(d)) / 2;
      x[2] = c / x[1];
      if (x[2] < x[1]) {
        double s = x[2];
        x[2] = x[1];
        x[1] = s;
      }
      p = x;
    } else if (d == 0) {
      double x[1];
      x[0] = 1;
      // x[1] = (-b + sqrt(d)) / (2 * a);
      x[1] = (-b - sign * sqrt(d)) / 2;
      p = x;
    } else {
      double x[1];
      x[0] = 0;
      p = x;
    }
  }
  return p;
}
