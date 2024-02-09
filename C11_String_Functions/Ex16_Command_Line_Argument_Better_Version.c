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
     * 该程序的优点：
     *     1，使用字符检查输入是否合法
     *     2，使用switch break结构使得后续拓展功能变得便捷
     */

    // 检测参数列表中的参数是否合法
    for (int i = 1; argc > 1 && i < argc; i++) {
        if (argv[i][0] != '-' || strlen(argv[i]) != 2) {
            printf("error, illegal argument detacted\n");
            return 0;
        }
    }

    char buffer;
    char choice;
    // 如果没有参数，就将参数设置为'p'
    if (argc == 1) {
        choice = 'p';
    } else {
        choice = argv[1][1];
    }
    switch (choice) {
        case 'p':
            while ((buffer = getchar()) != EOF) {
                putchar(buffer);
            }
            break;
        case 'u':
            while ((buffer = getchar()) != EOF) {
                buffer = toupper(buffer);
                putchar(buffer);
            }
            break;
        case 'l':
            while ((buffer = getchar()) != EOF) {
                buffer = tolower(buffer);
                putchar(buffer);
            }
            break;
        default:
            printf("argument can't not be identified\n");
            break;
    }

    return 0;
}