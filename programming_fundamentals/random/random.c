#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(0)); // reset the random
  int A = rand() % 10; // random number between 1 and 9
  printf("Random Number: %i", A);
  return 0;
}
