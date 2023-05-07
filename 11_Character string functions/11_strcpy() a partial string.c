/* copy2.c -- 使用 strcpy() */
#include <stdio.h>
#include <string.h>  // 提供strcpy()的函数原型
#define WORDS "beast"
#define SIZE 40
int main(void) {
    const char* orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char* ps;
    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig); // 从copy + 7的位置开始拷贝orig，拷贝的时候会把orig字符串最后的空字符也拷贝过去
    puts(copy); // 从copy的位置开始读取并打印字符串
    puts(ps); // 从copy + 7的位置开始打印字符串
    return 0;
}