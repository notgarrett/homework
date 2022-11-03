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

int iterativeCount(struct Node *p) {
  int x = 0;
  while (p != NULL) {
    x++;
    p = p->next;
  }
  return x;
}

void insert(struct Node *p, int index, int dataInsert) {
  if (iterativeCount(p) < index || index <= 0)
    return;
  if (index == 1) {
    struct Node *nodeToInsert = (struct Node *)malloc(sizeof(struct Node *));
    nodeToInsert->data = dataInsert;
    nodeToInsert->next = p;
    first = nodeToInsert;
  }
  for (int i = 2; i < index - 1; i++) {
    p = p->next;
  }
  struct Node *temp2 = p->next;
  struct Node *nodeToInsert = (struct Node *)malloc(sizeof(struct Node *));
  nodeToInsert->data = dataInsert;
  nodeToInsert->next = temp2;
  p->next = nodeToInsert;
}

int main() {
  int size = 7;
  int input[] = {2, 4, 6, 8, 10, 12, 14};

  createList(input, size);
  printf("\n");
  insert(first, 3, 55);
  traversePrint(first);
  return 0;
}
