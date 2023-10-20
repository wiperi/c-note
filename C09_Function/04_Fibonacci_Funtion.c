// 计算第n位的Fibonacci数

#include <stdio.h>

/*
循环思路：
    如果n为0和1，则返回特殊值；
    如果n>=3，用n = 3的情况构思循环结构，需要3次计算；
    第一次计算出f(0)和f(1)的和；
    第一次计算出f(1)和f(2)的和；
    第一次计算出f(2)和f(3)的和；
*/
int fibonacci_by_looping(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int left = 0;
    int right = 1;
    int ret = 0;

    for (int i = 2; i <= n; i++) {
        ret = left + right;
        left = right;
        right = ret;
    }

    return ret;
}

/*
递归思路：
    根据Fibonacci函数的定义，F(n) = F(n - 1) + F(n - 2)
*/
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", fibonacci_by_looping(i));
    }
}
