#include <stdio.h>

int multiply(int a, int b) {
    if (b == 1) {
        return a;
    } else {
        return a + multiply(a, b - 1);
    }
}

int square(int a) {
    return multiply(a, a);
}

int cube(int a) {
    return multiply(square(a), a);
}

int main(void) {
    printf("%d", cube(4));
}