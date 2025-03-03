#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack *st = create_stack();
  push(st, 5);
  push(st, 3);
  push(st, 10);
  pop(st);

  printf("%d, %d, %d\n", st->size, st->top, st->data[st->top - 1]);

  return 0;
}
