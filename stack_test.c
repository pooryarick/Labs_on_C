#include "stack.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void stack_test_1() {
  Stack *st = create_stack();
  push(st, 5);
  push(st, 3);
  pop(st);
  push(st, 10);
  assert(st->top == 2 && st->data[st->top - 1] == 10 &&
         st->data[st->top - 2] == 5);
}

int main() {
  stack_test_1();
  return 0;
}
