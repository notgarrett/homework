#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_
#import <stdio.h>
#import <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} LIST_NODE;

typedef struct list {
  int count;
  LIST_NODE *head;
  LIST_NODE *rear;
} CIRCULAR_LIST;

inline CIRCULAR_LIST *createList() {
  CIRCULAR_LIST *list;
  list = (CIRCULAR_LIST *)malloc(sizeof(CIRCULAR_LIST *));

  if (!list)
    return list;

  list->count = 0;
  list->head = NULL;
  list->rear = NULL;
  return list;
}

inline void addNode(CIRCULAR_LIST *list, int data, int index) {
  LIST_NODE *node;
  node = (LIST_NODE *)malloc(sizeof(LIST_NODE *));
  if (!node || index <= 0)
    return;
  index = index % list->count;
  node->data = data;
  if (list->rear == NULL && list->head == NULL) {
    list->rear = node;
    list->head = node;
    node->next = node;
    return;
  }
  if (index == 1) { // Set head to node.
    node->next = list->head;
    list->head = node;
    list->rear->next = node;
  }

  LIST_NODE *rearNode = list->head;
  for (int i = 2; i < index; i++) {
    rearNode = rearNode->next;
  }
  LIST_NODE *nextNode = rearNode->next;
  rearNode->next = node;
  node->next = nextNode;

  if (index == list->count)
    list->rear = node;
  list->count++;
}

inline void deleteNode(CIRCULAR_LIST *list, int index) {
  if (index <= 0)
    return;

  if (list->count == 1) {
    free(list->head);
    list->head = NULL;
    list->rear = NULL;
  }
  index = index % list->count;
  if (index == 1) {
    LIST_NODE *tempNode = list->head;
    list->rear->next = list->head->next;
    free(tempNode);
    return;
  }

  LIST_NODE *rearNode = list->head;
  for (int i = 2; i < index; i++) {
    rearNode = rearNode->next;
  }

  LIST_NODE *currentNode = rearNode->next;
  LIST_NODE *nextNode = currentNode->next;

  rearNode->next = nextNode;
  free(currentNode);

  if (index == list->count)
    list->rear = rearNode;
  list->count--;
}

inline void printList(CIRCULAR_LIST *list) {
  LIST_NODE *tempNode = list->head;
  do {
    printf("%d \n", tempNode->data);
    tempNode = tempNode->next;
  } while (tempNode != list->rear);
}

inline void sortList(CIRCULAR_LIST *list) { return; }

#endif