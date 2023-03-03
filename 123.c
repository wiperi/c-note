#include <stdio.h>

int main(void)
{
    double apple = 12.123;

    printf("%1.1f\n", 1.12);
    printf("%16f\n", apple);
    printf("%+032f\n", apple);

    return 0;
}