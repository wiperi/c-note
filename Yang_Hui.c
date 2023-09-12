// 杨辉三角
/*
1
1    1
1    2    1
1    3    3    1
1    4    6    4    1
*/

#include <stdio.h>

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

int main() {
    int i, j;
    int a[10][10] = {{}};
    printf("\n");

    // 给二维数组赋值
    for (i = 0; i < 10; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    print2d(10, 10, a);

    for (i = 2; i < 10; i++)
        for (j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    print2d(10, 10, a);

    // 打印输出二维数组的值
    for (i = 0; i < 10; i++) {
        for (j = 0; j <= i; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}