#include <stdio.h>
#include <stdlib.h>

/* 
文件说明：
从用户输入获取文件名并打开，然后将指定字符替换
 */
int main(int argc, char* argv[]) {

///////////////////////////从输入读取地址并打开文件///////////////////////////////////
    puts("Input the file's name you wana open.");
    char fileName[FILENAME_MAX];
    FILE *file;
    scanf("%s", fileName);
    if ((file = fopen(fileName, "r+")) == NULL) {
        printf("Can't open: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
///////////////////////////从输入读取地址并打开文件///////////////////////////////////

    int ch;
    int operationCounts = 0; // 加入操作次数限制，防止while进入无限循环，生成超大文件
    while ((ch = fgetc(file)) != EOF && operationCounts < 1000) {
        
        if (ch == 'a') {

            fseek(file, -1L, SEEK_CUR); // 将文件指针退回1个字符
            fputc('b',file);            // 将下一个字符修改
            fseek(file, 2L, SEEK_CUR);  // 将文件指针前移2个字符
        }
        operationCounts++;
    }
    exit(0);
}