#include <math.h>
#include <stdio.h>

void reversedTriangle(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            printf("%2d*%2d\t", i, j);
        }
        puts("");
    }
}

void triangle(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d*%d\t", i, j);
        }
        puts("");
    }
}

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void insertionSort(int *a, int len) {
    for (int i = 1; i < len; i++) {
        int temp = a[i];

        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void bubbleSort(int *a, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[i] > a[j]) {
                swap(a, i, j);
            }
        }
    }
}

void selectionSort(int *a, int len) {
    for (int i = 0; i < len; i++) {
        int minI = i;

        int j;
        for (j = i + 1; j < len; j++) {
            if (a[j] < a[minI]) {
                minI = j;
            }
        }
        swap(a, i, minI);
    }
}

void arrayPointers(void) {
    int arr[] = {1, 2, 4, 5};
    int *par = arr;
    // 两种语法打印
    for (int i = 0; i < 4; i++) {
        printf("%d ", par[i]);
    }
    puts("");
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(par + i));
    }
    // 地址的区别
    puts("");
    printf("%p\n", &arr[0]);
    printf("%p\n", par);
    printf("%p\n", *par);
    // 两种语法打印二维数组
    int arr2d[3][2] = {{1, 2}, {4, 5}, {7, 8}};
    int(*par2d)[2] = arr2d;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", arr2d[i][j]);
        }
    }
    puts("");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", arr2d[i][j]);
        }
    }
    puts("");
}

/*
水仙花数
 */
int narcissisticNumber(int n) {
    int n1, n2, n3;
    n3 = n / 100;
    n2 = n / 10 % 10;
    n1 = n % 10;
    if (pow(n1, 3) + pow(n2, 3) + pow(n3, 3) == n) {
        return 1;
    }
    return 0;
}

/*
003、【题目】猴子吃桃问题

猴子吃桃问题：猴子第一天吃了若干个桃子，当即吃了一半，还不解馋，又多吃了一个；
第二天，吃剩下的桃子的一半，还不过瘾，又多吃了一个；以后每天都吃前一天剩下的一半多一个，到第10天想再吃时，只剩下一个桃子了。问第一天共吃了多少个桃子？
 */
int peachProblem(int left, int days) {
    // preDay / 2 - 1 == curDay
    // so (curDay + 1) * 2 == preDay
    if (days <= 1) {
        return left;
    }
    return peachProblem((left + 1) * 2, days - 1);
}

int main(void) {
    printf("%d", peachProblem(1, 10));
}