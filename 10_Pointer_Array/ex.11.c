/*
11.编写一个程序，声明一个int类型的3×5二维数组，并用合适的值初始
化它。该程序打印数组中的值，然后各值翻倍（即是原值的2倍），并显示
出各元素的新值。编写一个函数显示数组的内容，再编写一个函数把各元素
的值翻倍。这两个函数都以函数名和行数作为参数。
*/

#include <stdio.h>
#define ROWS 3
#define COLS 5
void print_array(int rows, int (*arr)[COLS]);
void double_it_and_print_it(int rows, int (*arr)[COLS]);
void print_array_1(int rows, int (*arr)[COLS]);
void double_it_and_print_it_1(int rows, int (*arr)[COLS]);

int main(void) {
    int arr[ROWS][COLS] = {
        {22, 45, 65, 213, 12}, {36, 234, 62, 12, 123}, {125, 12, 66, 12, 734}};
    print_array_1(ROWS, arr);
    double_it_and_print_it_1(ROWS, arr);
}
// 使用行数和指针作为形参
void print_array(int rows, int (*arr)[COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
}
// 使用行数和数组名作为形参
void print_array_1(int rows, int arr[][COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
}
// 使用变长数组作为形参作为形参
void print_array_2(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
}

void double_it_and_print_it(int rows, int (*arr)[COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] *= 2;
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
}
void double_it_and_print_it_1(int rows, int arr[][COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] *= 2;
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
}
