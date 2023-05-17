/* repeat.c -- 带参数的 main() */
#include <stdio.h>
int main(int argc, char* argv[]) {
    int count;
    printf("The command line has %d arguments:\n", argc);
    for (count = 0; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");
    return 0;
}

/**
 * 命令行中输入：PS C:\Users\15617\Documents\92 myGithub\TrainingGround> .\bin\program.exe 1 2 3
 * 
 * 输出：
 *     The command line has 4 arguments:
 *     0: C:\Users\15617\Documents\92 myGithub\TrainingGround\bin\123.exe
 *     1: 1
 *     2: 2
 *     3: 3
*/
