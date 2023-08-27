#include <stdio.h>
#include <stdlib.h>

void sequentialSearch(int* arr, int arr_size, int target_value) {
    if (arr_size == 0) {
        printf("empty list, search failure\n");
    } else {
        int i = 0;
        while (target_value > arr[i] && i < arr_size) {
            i++;
        }
        if (target_value == arr[i]) {
            printf("search success\n");
        } else {
            printf("target value didn't appear\n");
        }
    }
}

int main(void) {
    int arr[] = {6, 3, 2, 1, 3, 4, 6, 3, 2, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    sequentialSearch(arr, arr_size, 6);
}