#include <stdio.h>

/*
使用命令行参数：

终端输入：
$ C\bin\03_CommandLineArgument.exe 1 2 3

argc = 参数数量 + 1
argv[0]总是 = 文件名

终端输出：
argc: 4
argv:
C:\Users\Boris\Documents\10 MyGithub\C\bin\03_CommandLineArgument.exe
1
2
3
*/
int main(int argc, char *argv[]) {

    printf("argc: %d\n", argc);

    printf("argv: \n");

    for (int i = 0; i < argc; i++) {

        if (argv[i] == NULL) {
            printf("argv[%d] is NULL", i);
            break;
        }
        printf("%s\n", argv[i]);
    }
}