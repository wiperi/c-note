#include <stdio.h>

void insertionSort(int* arr, int arr_size) {
    int i = 1;
    int buffer;
    while (i < arr_size) {
        buffer = arr[i];
        int j = i - 1;
        while (j > -1 && buffer < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = buffer;
        i++;
    }
}

void insertionSort1(int* arr, int arr_size) {
    int buffer;
    for (int i = 0; i < arr_size; i++) {
        buffer = arr[i];

        int j = i - 1;
        while (j > -1 && buffer < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = buffer;
    }
}

int main(void) {
    int arr[] = {7, 4, 3, 2, 1, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    insertionSort1(arr, arr_size);

    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
}