// 用递归的方法构建阶乘的函数
#include <stdio.h>
int factorial_by_recursion(int n);
int factorial_by_loop(int n);
int main(void) { 
    printf("%d\n", factorial_by_recursion(1));
    printf("%d\n", factorial_by_loop(1));
}

int factorial_by_recursion(int n) {
    if (n == 1) {
        return 1;
    }
    int result;
    result = factorial_by_recursion(n - 1) * n;
    return result;
}

int factorial_by_loop(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}