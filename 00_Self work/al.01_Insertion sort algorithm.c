/*
使用插入排序算法，将一个整数数组按从小到大排序
*/
#include <stdio.h>

int main(void) {
    int arr[5] = {3, 2, 1, 5, 4};
    int cache;
    // 将第i个元素排序，得到一个数组，前i + 1个元素为有序，后面为无序
    for (int i = 1; i < 5; i++) {
        // 将要排序的元素放入flag中
        cache = arr[i];
        // 将被排序元素和它之前的每一个元素进行比较，以确定被排序元素的插入位置
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > cache) {
                if (j == 0) {
                    arr[j + 1] = arr[j];
                    // 若arr[j] > cache且j == 0，则直接将cache放入arr[0]中
                    arr[j] = cache;
                } else {
                    arr[j + 1] = arr[j];
                }
            } else { // 若arr[j] <= cache;
                arr[j + 1] = cache;
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}