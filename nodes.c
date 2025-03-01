#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};
int count(struct node *n) {
  int cnt = 0;
  while (n != NULL) {
    cnt++;
    n = n->next;
  }
  return cnt;
}
void add_to_start(struct node **p, int v) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->value = v;
  n->next = *p;
  *p = n;
}
void add_to_end(struct node *n, int v) {
  while (n->next != NULL) {
    n = n->next;
  }
  struct node *m = (struct node *)malloc(sizeof(struct node));
  n->next = m;
  m->next = NULL;
  m->value = v;
}
void add_by_number(struct node *n, int num, int v) {
  for (int i = 1; i < num - 1; i++) {
    n = n->next;
  }
  struct node *m = (struct node *)malloc(sizeof(struct node));
  m->value = v;
  m->next = n->next;
  n->next = m;
}

void remove_node(struct node *n, int num) {
  for (int i = 1; i < num - 1; i++) {
    n = n->next;
  }
  n->next = n->next->next;
}
int find_node(struct node *n, int num) {
  for (int i = 1; i < num; i++) {
    n = n->next;
  }
  return n->value;
}
