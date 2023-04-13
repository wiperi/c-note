/*
2.编写一个程序，初始化一个double类型的数组，然后把该数组的内容
拷贝至3个其他数组中（在main()中声明这4个数组）。使用带数组表示法的
函数进行第1份拷贝。使用带指针表示法和指针递增的函数进行第2份拷贝。
把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。第3
个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指
针。也就是说，给定以下声明，则函数调用如下所示：
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];
copy_arr(target1, source, 5);
copy_ptr(target2, source, 5);
copy_ptrs(target3, source, source + 5);
*/

#include <stdio.h>
void copy_arr(double target[], double source[], int arrSize);
void copy_ptr(double *target, double *source, int arrSize);
void copy_ptrs(double target[], double source[], double *end);

int main(void) {
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    double target1[5];
    copy_arr(target1, source, 5);
    printf("\n");

    double target2[5];
    copy_ptr(target2, source, 5);
    printf("\n");

    double target3[5];
    copy_ptrs(target3, source, source + 5);
    printf("\n");
}

void copy_arr(double target[], double source[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        target[i] = source[i];
        printf("%.2f,", target[i]);
    }
}

void copy_ptr(double *target, double *source, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        *(target + i) = *(source + i);
        printf("%.2f,", *(target + i));
    }
}

void copy_ptrs(double target[], double source[], double *end) {
    
}