#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>

int count(node *n) {
  int cnt = 0;
  while (n != NULL) {
    cnt++;
    n = n->next;
  }
  return cnt;
}
void add_to_start(node **p, int v) {
  node *n = malloc(sizeof(node));
  n->value = v;
  n->next = *p;
  *p = n;
}
void add_to_end(node *n, int v) {
  while (n->next != NULL) {
    n = n->next;
  }
  node *m = malloc(sizeof(node));
  n->next = m;
  m->next = NULL;
  m->value = v;
}
void add_by_number(node *n, int num, int v) {
  for (int i = 1; i < num - 1; i++) {
    n = n->next;
  }
  node *m = malloc(sizeof(node));
  m->value = v;
  m->next = n->next;
  n->next = m;
}

void remove_node(node *n, int num) {
  for (int i = 1; i < num - 1; i++) {
    n = n->next;
  }
  node *m = n->next;
  n->next = m->next;
  free(m);
}
int find_node(node *n, int num) {
  for (int i = 1; i < num; i++) {
    n = n->next;
  }
  return n->value;
}

void clean_memory(node *n) {
  node *m;
  while (n->next != NULL) {
    m = n->next;
    free(n);
    n = m;
  }
  free(m);
}
