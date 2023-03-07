// 用户输入数字，判断该数字为几位数
#include <stdio.h>

int main(void)
{
    float x = 0, n = 1, t = 1;
    scanf("%f", &x);

    float i = (x / n);

    while ((x/n) < 1 || (x/n) >= 10)
    {
        t += 1;
        n *= 10;
    }

    printf("%.0f", t);

    return 0;
}