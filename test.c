#include <stdio.h>

void print(int *arr, int len);

int main() {
    // Write C code here
    int arrlen;
    printf("How many number do you wana store?\n");
    scanf("%d", &arrlen);
    int arr[arrlen];
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }

    print(arr, len);

    return 0;
}

void print(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        printf("%d ", i);
    }
}