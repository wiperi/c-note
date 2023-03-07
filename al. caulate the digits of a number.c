// 用户输入数字，判断该数字为几位数
#include <stdio.h>

int main(void)
{
    double x = 0, n = 1, t = 1;
    scanf("%lf", &x);

    double i = (x / n);

    while ((x/n) < 1 || (x/n) >= 10)
    {
        t += 1;
        n *= 10;
    }

    printf("%.0f", t);

    return 0;
}