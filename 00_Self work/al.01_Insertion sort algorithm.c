/*
使用插入排序算法，将一个整数数组按从小到大排序
*/
#include <stdio.h>

int main(void) {
    int arr[5] = {3, 2, 1, 5, 4};
    int buffer;
    for (int i = 1; i < 5; i++) {
        buffer = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > buffer) {
                if (j == 0) {
                    arr[j + 1] = arr[j];
                    // 若arr[j] > cache且j == 0，则直接将buffer放入arr[0]中
                    arr[j] = buffer;
                } else {
                    arr[j + 1] = arr[j];
                }
            } else { // 若arr[j] <= buffer;
                arr[j + 1] = buffer;
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}