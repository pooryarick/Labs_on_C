#include "nodes.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void list_test_1() {
  node *head = malloc(sizeof(node));
  head->value = 3;
  add_to_start(&head, 12);
  add_to_start(&head, 18);
  add_to_end(head, 10);
  remove_node(head, 2);
  add_by_number(head, 2, 100);
  assert(count(head) == 4 && find_node(head, 1) == 18 &&
         find_node(head, 2) == 100 && find_node(head, 3) == 3 &&
         find_node(head, 4) == 10);
  clean_memory(head);
}

int main() {
  list_test_1();

  return 0;
}
