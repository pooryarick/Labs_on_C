typedef struct node {
  int value;
  struct node *next;
} node;
int count(node *n);
void add_to_start(node **p, int v);
void add_to_end(node *n, int v);
void add_by_number(node *n, int num, int v);
void remove_node(node *n, int num);
int find_node(node *n, int num);
void clean_memory(node *n);
