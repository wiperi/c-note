#include <stdio.h>

void SequentialSearchAlgorithm(int* arr, int arr_size, int target_value) {
    if (arr_size == 0) {
        printf("empty list, search failure\n");
    } else {
        int i = 0;
        while (target_value > arr[i] && i < arr_size) {
            i++;
        }

        if (i < arr_size) {
            printf("search success\n");
        } else {
            printf("target value didn't appear\n");
        }
    }
}

void InsertionSortAlgorithm(int* arr, int arr_size) {
    int buffer;
    int i = 1;
    while (i < arr_size) {
        buffer = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > buffer) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = buffer;
        i++;
    }
}

// a bad version
void InsertionSortAlgorithm1(int* arr, int arr_size) {
    int buffer;
    int i = 1;
    while (i < arr_size) {
        buffer = arr[i];
        int j = i - 1;
        while (j >= 0) {
            if (arr[j] > buffer) {
                if (j == 0) {
                    arr[j + 1] = arr[j];
                    arr[j] = buffer;
                    j--;
                } else {
                    arr[j + 1] = arr[j];
                    j--;
                }
            } else {
                arr[j + 1] = buffer;
                break;
            }
        }
        i++;
    }
}

void PrintArray(int* arr, int arr_size) {
    printf("[");
    for (int i = 0; i < arr_size; i++) {
        if (i != arr_size - 1)
            printf("%d, ", arr[i]);
        else
            printf("%d]\n", arr[i]);
    }
}

int BinarySearch(int* arr, int left, int right, int target_value) {
    if (left <= right) {
        int middle = left + ((right - left) + 1) / 2;
        if (arr[middle] == target_value) {
            return middle;
        } else if (target_value > arr[middle]) {
            return BinarySearch(arr, middle + 1, right, target_value);
        } else {
            return BinarySearch(arr, left, middle - 1, target_value);
        }
    } else {
        return -1;
    }
}

int BinarySearchV2(int* arr, int left, int right, int target_value) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == target_value) {
            return middle;
        } else if (target_value > arr[middle]) {
            return BinarySearch(arr, middle + 1, right, target_value);
        } else {
            return BinarySearch(arr, left, middle - 1, target_value);
        }
    } else {
        return -1;
    }
}

int main(void) {
    int arr[] = {1, 2, 5, 7, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    SequentialSearchAlgorithm(arr, arr_size, 3);
    InsertionSortAlgorithm1(arr, arr_size);
    PrintArray(arr, arr_size);
    printf("%d\n", BinarySearch1(arr, 0, arr_size - 1, 30));
}
