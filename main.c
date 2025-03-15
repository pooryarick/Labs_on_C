#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack *st = create_stack();
  push(st, 5);
  push(st, 3);
  push(st, 10);
  int p = pop(st);
  p = pop(st);
  printf("%d\n", p);
  printf("%d, %d, %d\n", st->size, st->top, st->data[st->top - 1]);
  clean_memory(st);
  return 0;
}
