#include <stdio.h>

int main(void) {
  int N;
  puts("Input a integer: ");
  scanf("%i", &N);
  /* if (N % 2) {
    puts("Odd");
  } else {
    puts("Even");
  } */
  // Ternary syntax
  printf("The number is %s\n", (N % 2) ? "Odd" : "Even");
  puts("Done.");
  return 0;
}