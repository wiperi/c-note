#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。

void reverseInput(char prechar) {
    char ch;
    if ((ch = getchar()) != '\n') {
        reverseInput(ch);
    }
    putchar(prechar); // 递归调用后面的语句逆序执行
    return;
}

int main() {

    reverseInput(getchar());
}