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
#define ROWS 3
#define COLS 5
double calcu_averge(int rows, double (*arr)[COLS]);
void input_array(int rows, double arr[][COLS]);
double find_the_maxnum(int rows, int cols, double arr[rows][cols]);

int main(void) {
    printf(
        "Please input 3 groups of numbers. Each groups contains 5 double float "
        "point numbers\n");
    double arr[ROWS][COLS];
    input_array(ROWS, arr);
    for (int i = 0; i < ROWS; i++) {
        printf("averge of arr[%d][] is %.2f\n", i, calcu_averge(i, arr));
    }
    printf("%.2f", find_the_maxnum(ROWS, COLS, arr));
}

void input_array(int rows, double (*arr)[COLS]) {
    for (int x = 0; x < rows; x++) {  // 运行15次scanf读取用户输入
        for (int y = 0; y < COLS; y++) {
            printf("arr[%d][%d] = ", x, y);
            scanf("%lf", &arr[x][y]);
            printf("\n");
        }
    }
    for (int x = 0; x < rows; x++) {  // 打印数组
        printf("arr[%d] = {", x);
        for (int y = 0; y < COLS; y++) {
            printf("%.2f", arr[x][y]);
            if (y < COLS - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}
double calcu_averge(int rows, double (*arr)[COLS]) {
    double total = 0;
    for (int i = 0; i < COLS; i++) {
        total += arr[rows][i];
    }
    return total / COLS;
}
double find_the_maxnum(int rows, int cols, double arr[rows][cols]) {
    double max = 0;
    for (int x = 0; x < rows; x++) {  
        for (int y = 0; y < cols; y++) {
            if(max < arr[x][y]) {max = arr[x][y];}
        }
    }
    return max;
}