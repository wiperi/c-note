#include <stdio.h>
#include <stdlib.h>


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
/**
 * 一个糟糕的版本，解决问题的逻辑有问题导致了糟糕的代码结构
 */
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
/**
 * 该版本将中位数定义为中间靠右的那个数
 */
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
/**
 * 该版本将中位数定义为中间靠左的那个数
 */
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

void SelectionSort(int* arr, int arr_size) {
    int buffer;
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < arr[i]) {
                buffer = arr[i];
                arr[i] = arr[j];
                arr[j] = buffer;
            }
        }
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
int main(void) {
    int arr[] = {6,4,3,1,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    if (0) {
        SequentialSearchAlgorithm(arr, arr_size, 3);
        InsertionSortAlgorithm1(arr, arr_size);
        printf("%d\n", BinarySearchV2(arr, 0, arr_size - 1, 30));
    }
    SelectionSort(arr, arr_size);
    PrintArray(arr, arr_size);
    
}
