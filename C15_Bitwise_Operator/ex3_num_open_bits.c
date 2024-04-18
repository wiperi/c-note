// 3.编写一个函数，接受一个 int 类型的参数，并返回该参数中打开位的
// 数量。在一个程序中测试该函数。

#include <limits.h>
#include <stdio.h>

int num_open_bits(int x) {
    int res = 0;

    int size = sizeof(int) * CHAR_BIT;
    for (int i = 0; i < size; i++) {
        res += (x >> i) & 1;
    }
    
    return res;
}

int main(int argc, char *argv[]) {
    printf("%d\n", num_open_bits(0xf000f000));
}