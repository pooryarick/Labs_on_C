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
  clean_memory(st);
}
void stack_test_2() {
  Stack *st = create_stack();
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  push(st, 10);
  assert(st->size == 20);
  pop(st);
  assert(st->size == 10);
  clean_memory(st);
}
void stack_test_3() {
  Stack *st = create_stack();
  push(st, 10);
  push(st, 2);
  push(st, 6);
  assert(pop(st) == 6 && pop(st) == 2 && pop(st) == 10);
  clean_memory(st);
}

int main() {
  stack_test_1();
  stack_test_2();
  stack_test_3();
  return 0;
}
