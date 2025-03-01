#include "find_roots.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  double a = 1;
  double b = 0;
  double c = -1;
  double *roots = find_roots(a, b, c);

  if (roots[0] == 0) {
    printf("[]\n");
  } else if (roots[0] == 1) {
    printf("[%lf]\n", roots[1]);
  } else if (roots[0] == 2) {
    printf("[%lf, %lf]\n", roots[1], roots[2]);
  }
  return 0;
}
