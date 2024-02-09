/*
指针和多维数组
*/
#include <stdio.h>

int main() {

    // 声明并初始化一个二维数组
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 打印二级数组中每一个元素的地址
    printf("first it is address\n\n");
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 3; k++) {
            printf("%p\n", &arr[i][k]);
        }
    }

    printf("\n");

    // 打印一级数组中每一个元素的地址
    for (int i = 0; i < 2; i++) {
        printf("%p\n", &arr[i]);
    }

    printf("\n");

    // 打印数组的地址
    printf("%p\n", &arr);

    printf("\nthen it is value\n\n");

    // 打印二级数组中每一个元素的值
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 3; k++) {
            printf("%p\n", arr[i][k]);
        }
    }

    printf("\n");

    // 打印一级数组中每一个元素（子数组）的值
    for (int i = 0; i < 2; i++) {
        printf("%p\n", arr[i]);
    }

    printf("\n");

    // 打印数组名称对应的值
    printf("%p\n", arr);

    return 0;
}