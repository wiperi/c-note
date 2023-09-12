// 杨辉三角
/*
1
1    1
1    2    1
1    3    3    1
1    4    6    4    1
*/

#include <stdio.h>

void print2d(int x, int y, int arr[x][y]);

int main(void) {

    // 初始化二维数组
    int arr[10][10] = {{}};
    putchar('\n');
    print2d(10, 10, arr); // 打印数组

    // 第一次赋值
    for (int i = 0; i < 10; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    print2d(10, 10, arr); // 打印数组

    // 第二次赋值
    for (int i = 2; i < 10; i++) {
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    print2d(10, 10, arr); // 打印数组
}

void print2d(int x, int y, int arr[x][y]) {

    puts("***********************************************");

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%5d ", arr[i][j]);
        }
        putchar('\n');
    }
    puts("***********************************************");
}