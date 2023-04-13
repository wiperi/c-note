/*
4.编写一个函数，返回储存在double类型数组中最大值的下标，并在一
个简单的程序中测试该函数。
*/

#include <stdio.h>
int maxIndex(double arr[], int arrSize);

int main(void) {
    double arr[5] = {23,11,45,55,77.3};
    printf("%d", maxIndex(arr, sizeof arr / sizeof arr[0]));
}

int maxIndex(double arr[], int arrSize) {
    int result = arr[0];
    for (int i = 0; i < (arrSize - 1); i++) {
        if (arr[i] < arr[i + 1]) {
            result = i + 1;
        }
    }
    return result;
}