// 用户输入数字，判断该数字为几位数
#include <stdio.h>

int main(void)
{
    double x;
    double n = 1, t = 1;
    scanf("%f", &x);

    if (x>=1 || x<10 /* condition */)
    {
        printf("yes");
    }
    else
    {
        printf("hellno");
    }

    
    
    return 0;
}