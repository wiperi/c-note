// 用递归的方法构建阶乘的函数
#include <stdio.h>
int fac(int n);

int main(void) { printf("%d", fac(5)); }

int fac(int n) {
    if (n == 1) {
        return 1;
    }
    int result;
    result = fac(n - 1) * n;
    return result;
}