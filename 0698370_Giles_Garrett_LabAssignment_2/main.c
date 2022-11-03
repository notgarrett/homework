#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int binary_to_uint(const char *b) {
  unsigned int val = 0;
  int i = 0;

  if (b == NULL)
    return 0;

  while (b[i] == '0' || b[i] == '1') { // Found another digit.
    val <<= 1;
    val += b[i] - '0';
    i++;
  }
  return val;
}

// Error messages (referenced from the textbook.)
const char closMiss[] = "Close paren missing at line";
const char openMiss[] = "Open paren missing at line";

int main(void) {
  unsigned int x;
  char y[] = "01011111101111100100000000000000";
  x = binary_to_uint(y);
  printf("%d", x);
  return 0;
}