/* fgets1.c -- 使用 fgets() 和 fputs() */

// fgets()函数读取字符写入指定文件并在结尾加上空字符，直到读取到换行符或者已经读取了n - 1次为止，它不会去掉换行符。返回输入字符串首字符的地址

// fputs()函数从目标地址开始读取字符串，打印到指定文件中，不会自动添加换行符。返回值是输出的字符数

#include <stdio.h>
#define STLEN 14
int main(void) {
    char words[STLEN];
    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
    return 0;
}
