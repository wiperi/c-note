/*
3.编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的
程序中测试该函数。
*/
#include <stdio.h>
int max(int arr[], int arrSize);

int main(void) {
    int arr[5] = {23, 12, 23, 55, 77};
    printf("%d", max(arr, sizeof arr / sizeof arr[0]));
}

int max(int arr[], int arrSize) {
    int result = arr[0];
    for (int i = 0; i < (arrSize - 1); i++) {  // 只需要遍历到数组倒数第二个数字
        if (arr[i] < arr[i + 1]) {
            result = arr[i + 1];
        }
    }
    return result;
}
