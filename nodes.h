struct node {
  int value;
  struct node *next;
};
int count(struct node *n);
void add_to_start(struct node **p, int v);
void add_to_end(struct node *n, int v);
void add_by_number(struct node *n, int num, int v);
void remove_node(struct node *n, int num);
int find_node(struct node *n, int num);
