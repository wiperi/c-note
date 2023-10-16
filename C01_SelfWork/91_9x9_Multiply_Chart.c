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
            printf("%2d*%2d\t", i, j);
        }
        puts("");
    }
}

int main(void) {
    triangle();
    reversedTriangle();
}