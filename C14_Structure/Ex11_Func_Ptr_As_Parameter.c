/* 11.编写一个名为transform()的函数，接受4个参数：内含double类型数据
的源数组名、内含double类型数据的目标数组名、一个表示数组元素个数的
int类型参数、函数名（或等价的函数指针）。transform()函数应把指定函数
应用于源数组中的每个元素，并把返回值储存在目标数组中。例如：
transform(source, target, 100, sin);
该声明会把target[0]设置为sin(source[0])，等等，共有100个元素。在一
个程序中调用transform()4次，以测试该函数。分别使用math.h函数库中的两
个函数以及自定义的两个函数作为参数。 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double soMuchFun(double a) {
    return 233.33;
}
// 计算浮点数一共有几位
double howManyDitgits(double a) {
    int integer_part = (int)a;
    int decimal_part = abs((int)((a - integer_part) * 1000000));

    int count = 0;
    while (integer_part >= 1 || integer_part <= -1) {
        integer_part /= 10;
        count++;
    }

    while (decimal_part >= 1) {
        if (decimal_part % 10 == 0) {
            decimal_part /= 10;
            continue;
        }

        decimal_part /= 10;
        count++;
    }

    return (double)count;
}
// 根据传入的函数指针，将source数组中的元素处理后输入target数组
void transform(double source[], double target[], int arr_size, double (*pf)(double)) {
    for (int i = 0; i < arr_size; i++) {
        target[i] = pf(source[i]);
    }
}
// 打印数组
void print(double arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%8.4f ", arr[i]);

        if ((i + 1) % 7 == 0) {
            putchar('\n');
        }
        
    }
}

int main(void) {
    double source[100];
    double target[100];
    int arr_size = sizeof(source) / sizeof(source[0]);

    // assign the random value to the array
    srand((unsigned int) time(NULL));
    for (int i = 0; i < arr_size; i++) {
        source[i] = rand() % 200 + 1;
    }

    transform(source, target, arr_size, soMuchFun);
    print(target, arr_size);
    puts("\n***********************************");

    transform(source, target, arr_size, howManyDitgits);
    print(target, arr_size);
    puts("\n***********************************");

    transform(source, target, arr_size, sin);
    print(target, arr_size);
    puts("\n***********************************");

    transform(source, target, arr_size, tan);
    print(target, arr_size);
}