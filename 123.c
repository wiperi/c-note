/*用户输入n，创建一个包含n个随机数的数组，然后将其排序之后按顺序打印*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));

    int n;
    printf("Input a number X to create an array containing X elements...\n");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i <= n - 1; i++)
    {
        array[i] = rand()%50;
        printf("%d ", array[i]);
    }
    
    printf("\n");
    
    int buffer;
    for (int i = 0; i <= n - 1; i++)
    {
        if (array[i] <= array[i + 1])
        {
        }
        else
        {
            buffer = array[1];
            array[i] = array[i+1];
            array[i+1] = buffer;
        }
    }

    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", array[i]);
    }
}