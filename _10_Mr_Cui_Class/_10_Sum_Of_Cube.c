#include <stdio.h>

// 传统递归方法
// 占用多层stack，调用深度为 = n
int multiply(int a, int b) {
    if (b == 1) {
        return a;
    } else {
        return a + multiply(a, b - 1);
    }
}

// 尾部调用优化 TCO(tail call optimation)
// 通过在参数中加入累加器，将原本多层的stack占用，优化到只占用一层stack
int multiplyBetter(int a, int b, int accumulator) {
    if (b == 0) {
        return accumulator;
    } else {
        return multiplyBetter(a, b - 1, accumulator + a);
    }
}

int square(int a) {
    return multiply(a, a);
}

int cube(int a) {
    return multiply(square(a), a);
}

// test module
int main(void) {
    printf("%d", multiplyBetter(3, 4, 0));
}