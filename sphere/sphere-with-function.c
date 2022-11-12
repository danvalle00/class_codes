#include <stdio.h>
#define PI 3.14

float volume(float radius) {
  float vol = (4 * PI * radius) / 3;
  return vol;
}

// void volume(float radius){
//   float vol = (4 * PI * radius) / 3;
//   printf("%2.f"vol);
// }

int main(void) {
  int raio;
  puts("Radius: ");
  scanf("%i", &raio);
  printf("%.2f", volume(raio));
  // volume(raio);
  return 0;
}