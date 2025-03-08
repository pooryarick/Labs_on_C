#include "find_roots.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double e = 1E-7;
  double a = 1;
  double b = 0;
  double c = -1;
  double *roots = find_roots(a, b, c, e);

  if (roots[0] < e) {
    printf("[]\n");
  } else if (fabs(roots[0] - 1) < e) {
    printf("[%lf]\n", roots[1]);
  } else if (fabs(roots[0] - 2) < e) {
    printf("[%lf, %lf]\n", roots[1], roots[2]);
  }
  return 0;
}
