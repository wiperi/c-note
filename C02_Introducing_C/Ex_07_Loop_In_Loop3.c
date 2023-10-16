// 用while函数实现
#include <stdio.h>

int main(void) {
    int n = 3;
    while (n >= 1) {
        int t = n;
        while (t >= 1) {
            printf("Smile!");

            t = t - 1;
        }
        printf("\n");

        n = n - 1;
    }
}