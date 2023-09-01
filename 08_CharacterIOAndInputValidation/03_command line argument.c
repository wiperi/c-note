#include <stdio.h>

/*
使用命令行参数：

终端输入：
$ C\bin\03_CommandLineArgument.exe 1 2 3

终端输出：
argc: 4
argv:
C:\Users\Boris\Documents\10 MyGithub\C\bin\03_CommandLineArgument.exe
1
2
3
*/
int main(int argc, char *argv[]) {

    // 默认情况下，argc = 1，argv[0]为exe文件的路径
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