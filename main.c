#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->value = 5;
  head->next = (struct node *)malloc(sizeof(struct node));
  head->next->value = 8;
  head->next->next = (struct node *)malloc(sizeof(struct node));
  head->next->next->value = 3;
  head->next->next->next = (struct node *)malloc(sizeof(struct node));
  head->next->next->next->value = 7;
  head->next->next->next->next = NULL;

  remove_node(head, 2);
  add_to_start(&head, 12);
  add_to_end(head, 10);
  add_by_number(head, 3, 100);
  printf("%d\n", count(head));
  printf("%d\n", find_node(head, 4));
  return 0;
}
