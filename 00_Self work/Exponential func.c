// 定义一个函数来计算整数的指数幂
#include <stdio.h>

void calculate_exponent(int BasicNumber, int exponent);

void calculate_exponent(int BasicNumber, int exponent) {
    int n, result;
    result = BasicNumber;

    for (n = 1; n < exponent; n++) result = result * BasicNumber;

    printf("%d", result);
}

int main(void) {
    calculate_exponent(2, 4);

    return 0;
}