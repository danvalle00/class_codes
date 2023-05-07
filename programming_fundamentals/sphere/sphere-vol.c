#include <stdio.h>
#include <math.h>
#define pi 3.14

int main()
{
    float radius = 0;
    puts("Sphere Radius: ");
    scanf("%f", &radius);
    float volume = (4 / 3) * pi * pow(radius, 3);
    printf("The volume of a sphere of Radius %.2f is %2.f", radius, volume);
    return 0;

}
