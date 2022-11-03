#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void push(char *, char);

void pop(char *, char *);

void pushStringToStack(char *, char *);

void getTop(char *);

bool comparePalendrome(char *, char *);

int main(void) {
  char stack[25];
  char palendrome[] = "racecar";
  pushStringToStack(stack, palendrome);
  if (comparePalendrome(stack, palendrome) == 1)
    printf("%s is a palendrome", palendrome);
  else
    printf("%s is not a palendrome", palendrome);
}

bool comparePalendrome(char *stack, char *palendrome) {
  if (*palendrome == '\0')
    return 1;
  char temp;
  pop(stack, &temp);
  if (*palendrome == temp)
    return comparePalendrome(stack, ++palendrome);
  return 0;
}

void push(char *stack, char character) {
  if (*stack == '\0') {
    *stack = character;
    return;
  }
  char temp = *stack;
  *stack = character;
  push(++stack, temp);
}

void pushStringToStack(char *stack, char *string) {
  if (*string == '\0')
    return;
  push(stack, *string);
  pushStringToStack(stack, ++string);
}

void pop(char *stack, char *character) {
  if (*stack == '\0')
    return;
  char temp = *stack;
  *stack = *(stack + 1);
  pop(++stack, character);
  *character = temp;
}
