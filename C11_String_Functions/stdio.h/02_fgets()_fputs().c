/* fgets1.c -- 使用 fgets() 和 fputs() */

#include <stdio.h>
#define STLEN 14
int main(void) {
    char string[STR_LEN];
    
    puts("Enter a string, please.");

    // 读取字符写入指定文件并在结尾加上空字符，直到读取到换行符或者已经读取了n - 1次为止，它不会去掉换行符
    // @return 返回输入字符串首字符的地址, 读取失败返回NULL
    fgets(string, STR_LEN, stdin);
    
    printf("Your string twice (puts(), then fputs()):\n");
    puts(string);

    // 从目标地址开始读取字符串，打印到指定文件中，不会自动添加换行符
    // @return 返回成功输出的字符数
    fputs(string, stdout);
    
    puts("Enter another string, please.");
    
    fgets(string, STR_LEN, stdin);
    
    printf("Your string twice (puts(), then fputs()):\n");
    puts(string);
    fputs(string, stdout);
    puts("Done.");
    return 0;
}
