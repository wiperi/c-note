#include <stdio.h>
#define STR_LEN 10

int main(void) {
    char string[STR_LEN];

    // 读取buffer中的所有的字符，去掉换行符，写入到目标地址中
    // @return 返回读取到的字符串的首地址，读取失败返回NULL
    gets(string);

    // 从目标地址开始读取并打印字符串，打印到空字符停止，并在最后加上一个换行符
    // @return 返回输出的字符数，不包括自动追加的换行符
    puts(string);

    // 读取的字符数收到参数的限制，如果没有读取到换行符，丢弃剩余缓冲中的字符并终止程序
    // @return 返回读取到的字符串的首地址，读取失败返回NULL
    gets_s(string, STR_LEN);

    puts(string);
}