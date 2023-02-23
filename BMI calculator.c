#include <stdio.h>

int main()
{
    float weight, height;

    printf("please input your weight(kg) and height(m):");
    scanf("%f,%f", &weight, &height);


    float BMI;
    
    BMI = weight/(height * height);

    printf("your BMI is %f", BMI);
    return 0;
}