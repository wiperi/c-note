#include <stdio.h>

int* binarySearch(int arr[], int target, int l, int r) {
    if (l > r) {
        return NULL;
    } else if (l <= r) {
        int mid = (l + r) / 2;
        
        if (target == arr[mid]) {
            return arr + mid;
        } else if (target > arr[mid]) {
            binarySearch(arr, target, mid + 1, r);
        } else if (target < arr[mid]) {
            binarySearch(arr, target, l, mid - 1);
        }
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int* target = binarySearch(arr, 6, 0, arr_size);
    printf("%d %p", *target, target);
}