/*
16.编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出
来。该程序识别和实现下面的命令行参数：
-p 按原样打印
-u 把输入全部转换成大写
-l 把输入全部转换成小写
如果没有命令行参数，则让程序像是使用了-p参数那样运行。
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    /**
     * 缺点：
     *     1，没有输入检查
     *     2，处理参数的方式使得后续拓展困难
    */
   
    printf("c = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("v = %s\n", argv[i]);
    }

    char buffer;
    if (argc == 1 ||
        strcmp(argv[1], "-p") == 0) { // no argurment or arguement == -p
        while ((buffer = getchar()) != EOF) {
            putchar(buffer);
        }
    } else if (strcmp(argv[1], "-u") == 0) { // arguement == -u
        while ((buffer = getchar()) != EOF) {
            buffer = toupper(buffer);
            putchar(buffer);
        }
    } else { // arguement == -l
        while ((buffer = getchar()) != EOF) {
            buffer = tolower(buffer);
            putchar(buffer);
        }
    }
}