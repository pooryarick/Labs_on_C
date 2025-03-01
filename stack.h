typedef struct Stack {
  int *data;
  unsigned int size;
  unsigned int top;
} Stack;

Stack *create_stack();
void push(Stack *stack, int v);
int is_not_empty(Stack *stack);
int pop(Stack *stack);
