#include <stdio.h>

int main()
{
    float height = 0, weight = 0;
    puts("Your Height (meters): ");
    scanf("%f", &height);
    puts("Your Weight (kilograms): ");
    scanf("%f", &weight);
    float bmi = weight / (height * height);
    printf("Your BMI is: %.2f\n", bmi);

    if (bmi < 18.5)
        puts("Underweight!");
        else if (18.5 <= bmi < 24.9)
            puts("Normal Weight");
        else if (25 <= bmi < 29.9)
            puts("Overweight");
        else if (bmi >= 30 )
            puts("Obesity");

    return 0;
}
   