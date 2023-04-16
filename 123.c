#include <stdio.h>

void ex_3(void) {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", 65 + 5 - j);
        }
        printf("\n");
    }
}
void ex_4(void) {
    int k;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0, k = i; j <= i; j++, k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}
void ex_5(void) {
    int k = 0;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }
}

int main() { ex_5(); }