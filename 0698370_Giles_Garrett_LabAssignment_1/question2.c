#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure Declarations
typedef struct node {
  char data;
  struct node *link;
} STACK_NODE;

// Prototype Declarations
bool push(STACK_NODE **pList, char dataIn);
bool pop(STACK_NODE **pList, char *dataOut);

void pushLoop(STACK_NODE **pStackTop, char *string);
bool testPalendrome(STACK_NODE **pStackTop, char *palendrome);

int main(void) {
  STACK_NODE *pStackTop;

  char paldrome[] = "thissiht";
  pStackTop = NULL;
  puts("");
  // Sets string into stack
  pushLoop(&pStackTop, paldrome);

  // some bool that either confirms or denies it is a palendrome
  int test = testPalendrome(&pStackTop, paldrome);

  if (test)
    printf("%s is a palendrome!", paldrome);
  else
    printf("%s is not a palendrome", paldrome);

  return 0;
} // main

bool testPalendrome(STACK_NODE **pStackTop, char *paldrome) {
  if (*paldrome ==
      '\0') // If paldendrome is terminated, it means we are finished.
    return 1;

  char top;
  pop(pStackTop, &top);

  if (*(paldrome++) != top)
    return 0;
  return testPalendrome(pStackTop, paldrome);
}

bool push(STACK_NODE **pStackTop, char charIn) {
  // Local Definitions
  STACK_NODE *pNew;
  bool success;

  // Statements
  pNew = (STACK_NODE *)malloc(sizeof(STACK_NODE));
  if (!pNew)
    success = false;
  else {
    pNew->data = charIn;
    pNew->link = *pStackTop;
    *pStackTop = pNew;
    success = true;
  } // else
  return success;
} // push

void pushLoop(STACK_NODE **pStackTop, char *string) {
  // Simple recursion that pushes a string into the stack.
  if (*string == '\0')
    return;
  push(pStackTop, *(string++));
  pushLoop(pStackTop, string);
}

bool pop(STACK_NODE **pStackTop, char *charOut) {
  // Local Definitions
  STACK_NODE *pDlt;
  bool success;

  // Statements
  if (*pStackTop) {
    success = true;
    *charOut = (*pStackTop)->data;
    pDlt = *pStackTop;
    *pStackTop = (*pStackTop)->link;
    free(pDlt);
  } // else
  else
    success = false;
  return success;
} // pop
