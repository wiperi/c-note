#include <stdio.h>

int main()
{
    double inch, centimeter;

    printf("please input the value of inches:");
    scanf("%lf", &inch);

    centimeter = inch * 2.54;
    printf("%.2f inches equal to %.2f centimeters\n", inch, centimeter);

    getchar();
    getchar();

    return 0;
}