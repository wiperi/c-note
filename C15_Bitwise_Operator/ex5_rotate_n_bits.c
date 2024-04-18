// 5.编写一个函数，把一个 unsigned int 类型值中的所有位向左旋转指定数
// 量的位。例如，rotate_l(x, 4)把x中所有位向左移动4个位置，而且从最左端
// 移出的位会重新出现在右端。也就是说，把高阶位移出的位放入低阶位。在
// 一个程序中测试该函数。
#include <limits.h>
#include <stdio.h>

unsigned int rotate_left(unsigned int x, int n) {
    printf("%8.8x\n", x << n);
    printf("%8.8x\n", x >> (32 - n));
    return (x << n) | (x >> (32 - n));
}

int main(int argc, char* argv[]) {
    printf("%x\n", rotate_left(0xfa000000, 4));
}