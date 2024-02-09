/* fgets2.c -- 使用 fgets() 和 fputs() */
/* 注意，即使输入行的字符数超过了数组大小，程序依然能够将整行打印出来，因为超出的字符会在下一次循环中被打印 */
#include <stdio.h>
#define STLEN 10
int main(void) {
    char words[STR_LEN];
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STR_LEN, stdin) != NULL && words[0] != '\n') // 如果没有读到文件结尾而且读取到的不是空行，则真
        fputs(words, stdout);
    puts("Done.");
    return 0;
}
