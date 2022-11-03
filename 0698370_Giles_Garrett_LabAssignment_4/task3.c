// Create a linked list and traverse it to display the node data
// The input data are obtained from an array, you could have obtained this input
// at runtime either from user-keyboard (using scanf(), cin) or from a file.

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *first = NULL;

void createList(int input[], int size) {
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = input[0];
  first->next = NULL;
  last = first;

  printf("Created node 1 (header node) with data %d\n", first->data);

  for (i = 1; i < size; i++) {
    if (i == 1)
      printf("Started the for loop (we can use for loop in this case because "
             "we have been told by user to construct a list of these many "
             "nodes (=size))\n");
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = input[i];

    printf("Added node %d with data %d\n", i + 1, t->data);

    t->next = NULL;
    last->next = t;
    last = t;
  }

  printf("\n============================\nCompleted creating our list!\n");
}

void traversePrint(struct Node *p) {
  printf("Traversing and printing the nodes of the created linked list: ");
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int recursiveCount(struct Node *p) {
  if (p == NULL)
    return 0;
  return (1 + recursiveCount(p->next));
}

int main() {
  int size = 7;
  int input[] = {2, 4, 6, 8, 10, 12, 14};

  createList(input, size);
  printf("\n");
  printf("%d", recursiveCount(first));
  return 0;
}
