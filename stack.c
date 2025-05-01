#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define START_SIZE 10
#define MULTIPLIER 2

Stack *create_stack() {
  Stack *out = malloc(sizeof(Stack));
  out->size = START_SIZE;
  out->data = malloc(out->size * sizeof(int));
  out->top = 0;
  return out;
}

void push(Stack *stack, int v) {
  if (stack->top == stack->size) {
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
  }
  stack->data[stack->top] = v;
  stack->top++;
}
int is_not_empty(Stack *stack) {
  if (stack->top == 0) {
    return 0;
  } else {
    return 1;
  }
}

int pop(Stack *stack) {
  if (is_not_empty(stack) == 0) {
    printf("Stack is empty, can't pop element\n");
    exit(0);
  }
  if (stack->top == stack->size / MULTIPLIER + 1) {
    stack->size /= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
  }

  int out = stack->data[stack->top - 1];
  stack->top--;
  return out;
}

void clean_memory(Stack *stack) {
  free(stack->data);
  free(stack);
}
