#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void check(int* arr, int index, int arr_size) {
    // special situation: first element is 9
    if (index == 0 && arr[index] == 9) {
        printf("1 ");
    }

    arr[index] += 1;
    if (arr[index] == 10) {
        arr[index] = 0;
        check(arr, index - 1, arr_size);
    }
}
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* arr = (int*) malloc((digitsSize + 1) * sizeof(int));

    for (int i = 0; i < digitsSize; i++) {
        arr[i] = digits[i];
    }

    int i = 0;
    int have_9 = 0;
    while (i < digitsSize && arr[i++] == 9) {
        have_9 = 1;
        break;
    }

    if (!have_9) {
        arr[digitsSize - 1] += 1;
        *returnSize = digitsSize;
        return arr;
    } else {
        // have 9 situation;
        check(arr, digitsSize - 1, digitsSize);
        *returnSize = digitsSize;
        return arr;
    }
}

/* 
Pseudocode:

if (there is no 9 in the array) {
    last element += 1;
} else {
    // there is 9 in the array;
    check(last element);
} */



int main(void) {
    
    int arr[] = {1  };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int return_size;
    int* tar = plusOne(arr, arr_size, &return_size);
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", tar[i]);
    }
    free(tar);
}