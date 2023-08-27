/*用户输入n，创建一个包含n个随机数的数组，然后将其排序之后按顺序打印*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));
    // 为rand函数提供seed，将系统时间作为种子

    int n;
    printf("Input a number X to create an array containing X elements...\n");
    scanf("%d", &n);
    int array[n];
    // 根据用户输入创建一个规模为n的数组

    int a;
    for (a = 0; a <= n - 1; a++)
    {
        array[a] = rand() % 50;
        printf("%d ", array[a]);
    }
    // 将随机数赋值给数组，然后将数组打印

    printf("\n");

    int b;
    int c;
    int buffer;
    for (b = 1; b <= n; b++)
    {
        c= 0;
        while (c + 1 <= (n - 1))
        {
            if (array[c] > array[c + 1])
            {
                buffer = array[c];
                array[c] = array[c + 1];
                array[c + 1] = buffer;
            }
            c = c + 1;
        }
    }
    //将数字按照从小到大顺序排序

    int d;
    for (d = 0; d <= n - 1; d++)
    {
        printf("%d ", array[d]);
    }
    // 打印排序后的数组
}
