// 4.编写一个程序，接受两个int类型的参数：一个是值；一个是位的位
// 置。如果指定位的位置为1，该函数返回1；否则返回0。在一个程序中测试
// 该函数。

#include <stdio.h>
#include <assert.h>

unsigned int get_nth_digit(unsigned int x, unsigned int n) {
    assert(n <= 32);
    return x >> (n - 1) & 1;
}

int main(int argc, char* argv[]) {
    printf("%x\n", get_nth_digit(0x80000000, 32));
    printf("%x\n", get_nth_digit(0x80000000, 31));
}