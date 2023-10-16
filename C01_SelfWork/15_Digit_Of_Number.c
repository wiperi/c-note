// 用户输入数字，判断该数字为几位数
#include <stdio.h>
#include <math.h>

int countDigits(double num) {
    if (num < 0) {
        num = -num;  // 将负数转为正数以简化处理
    }

    int digits = 0;

    // 如果 num 是 0，则它有一位
    if (num < 1) {
        digits = 1;
    } else {
        while (num >= 1) {
            num /= 10;
            digits++;
        }
    }

    return digits;
}

int countDigits(double num) {
    if (isnan(num) || isinf(num)) {
        // 如果是 NaN 或无穷大，则返回 0
        return 0;
    }

    // 将负数转为正数以简化处理
    num = fabs(num);

    // 使用 log10 函数来计算数字的位数
    int digits = (int)log10(num) + 1;

    return digits;
}

int main(void)
{
    double x = 0, n = 1, t = 1;
    scanf("%lf", &x); //double类型在scanf中用%lf，在printf中用%f

    double i = (x / n);

    while ((x/n) < 1 || (x/n) >= 10)
    {
        t += 1;
        n *= 10;
    }

    printf("%.0f", t);

    return 0;
}