/*
13.编写一个程序，提示用户输入3组数，每组数包含5个double类型的数
（假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任
务。
a.把用户输入的数据储存在3×5的数组中
b.计算每组（5个）数据的平均值
c.计算所有数据的平均值
d.找出这15个数据中的最大值
e.打印结果
每个任务都要用单独的函数来完成（使用传统C处理数组的方式）。完
成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该
函数3次。对于处理其他任务的函数，应该把整个数组作为参数，完成任务c
和d的函数应把结果返回主调函数。
*/

#include <stdio.h>

int main(void) {
    printf(  // 提示用户输入三组数组
        "Please input 3 groups of numbers. Each groups contains 5 double float "
        "point numbers");
    double arr[3][5];
    for (int x = 0; x < 3; x++) {  // 运行15次scanf读取用户输入
        for (int y = 0; y < 5; y++) {
            printf("arr[%d][%d] = ", x, y);
            scanf("%lf", &arr[x][y]);
            printf("\n");
        }
    }
    for (int x = 0; x < 3; x++) {  // 打印数组
        printf("arr[%d] = {", x);
        for (int y = 0; y < 5; y++) {
            printf("%.2f,", arr[x][y]);
        }
        printf("}\n");
    }
}

