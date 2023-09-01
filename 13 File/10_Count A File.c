// 程序清单13.1 count.c程序
/* 使用标准IO，读取一个文件并统计其中的字符数 */

#include <stdio.h>
#include <stdlib.h> // 提供 exit()的原型
int main(int argc, char *argv[]) {

    int ch;   // 读取文件时，储存每个字符的地方
    FILE *fp; // “文件指针”
    unsigned long count = 0;
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);

        /*
        函数说明：
        exit函数关闭所有打开的文件并关闭程序，它的参数被传递给操作系统，用来表明程序是正常结束还是异常结束。

        参数的含义：
        0或宏EXIT_SUCCESS - 正常结束
        非0值或宏EXIT_FAILURE - 异常结束

        和return指令的区别；
        return将控制权返回上一级，exit终止整个程序（即使是被其他函数而不是main函数调用），在递归程序中它们有显著区别。

         */
        exit(EXIT_FAILURE);
    }

    /*
    函数说明：
    fopen函数打开文件

    参数含义：
    第一个参数是待打开文件的名称，第二个参数是打开文件的模式。

    返回值：
    返回一个文件指针（*FILE）
     */
    if ((fp = fopen(argv[1], "r")) == NULL) {

        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) { // 从fp指定的文件中获取一个字符，保存在ch中

        putc(ch, stdout); // 与 putchar(ch); 相同
        count++;
    }
    
    /* 
    函数说明：
    fclose函数关闭fp指定的文件，如果成功关闭，返回0，如果异常，返回EOF。
     */
    fclose(fp);

    printf("File %s has %lu characters\n", argv[1], count);
    return 0;
}
