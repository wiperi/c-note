#include <stdio.h>

int main(void) {
    
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%2d x %2d = %2d  ", j, i, j * i);
        }
        putchar('\n');
    }
}