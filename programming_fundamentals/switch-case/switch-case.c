#include <stdio.h>

int main(void) {
  int N;
  puts("Enter a integer: ");
  scanf("%i", &N);
  switch (N) {
  case 1:
    puts("The number was One");
    break;
  case 2:
    puts("The number was Two");
    break;
  case 3:
    puts("The number was Three");
    break;
  case 4:
    puts("The number was Four");
    break;
  case 5:
    puts("The number was Five");
    break;
  default:
    puts("Please input a number between 1 and 5");
  }
  puts("Done.");
  return 0;
}