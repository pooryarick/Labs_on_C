#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  node *head = malloc(sizeof(node));
  head->value = 5;

  add_to_start(&head, 12);
  add_to_end(head, 10);
  add_by_number(head, 3, 100);
  remove_node(head, 2);
  printf("%d\n", count(head));
  printf("%d\n", find_node(head, 2));
  clean_memory(head);
  return 0;
}
