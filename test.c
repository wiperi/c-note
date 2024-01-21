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

// 递归 排序 数单词 杨辉三角 100质数 5个学生三门课二维数组
void countWordgetchar(void) {
    int cnt = 0;
    char c;
    int isWord = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            isWord = 0;
        }
        if (c != ' ' && isWord == 0) {
            isWord = 1;
            cnt++;
        }
    }
    printf("%d", cnt);
}

void countWord(void) {
    char word[100];
    int cnt = 0;

    while (scanf("%s", word) == 1) {
        cnt++;
    }

    printf("%d", cnt);
}

void the100Prime(void) {
    int num = 1, count = 0;
    while (count < 100) {
        int isPrime = 1;
        for (int div = 2; div < num; div++) {
            if (num % div == 0) {
                isPrime = 0;
            }
        }
        if (isPrime)
            printf("%d ", num);
        num++;
        count++;
    }
}

void yanghui(void) {
    int arr[10][10] = {{}};

    for (int i = 0; i < 10; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    for (int i = 2; i < 10; i++) {
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

int countWordSingleLine(void) {
    printf("输入一行字符：\n");
    char ch;
    int i, count = 0, isWord = 0;
    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            isWord = 0;
        }
        if (ch != ' ' && isWord == 0) { // ch非空且不是word为空
            isWord = 1;
            count++;
        }
    }
    printf("总共有 %d 个单词\n", count);
    return 0;
}

void sort(void) {
    int arr[4] = {4, 3, 2, 1};

    for (int i = 0; i < 4 - 1; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[i] > arr[j]) {
                swap(arr, i, j);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
}

void the99(void) {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d\t", i, j);
        }
        puts("");
    }
}

void countWord_scan(void) {
    char c;
    int i = 0;
    char str[100];
    while (scanf("%s", NULL) == 1) {
        i++;
        if ((c = getchar()) == '\n') {
            break;
        }
    }
    printf("%d", i);
}

int main(void) {
    countWord_scan();
}