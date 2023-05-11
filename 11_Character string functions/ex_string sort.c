/*
目标：读取字符串，对字符串进行排序，打印字符串；

1，读取字符串，
*/

#include <stdio.h>
#define STRLEN 5
#define LIM 5
void getstr(char ar[][STRLEN]);
void printstr(char arr[][STRLEN], int n);

int main(void) {
    char words[LIM][STRLEN];
    getstr(words);

    putchar('\n');
    printstr(words, LIM);
}

void getstr(char ar[][STRLEN]) {
    /*
    如果没有超过读取上限，没有读到文件结尾，就一直读取字符串；
    如果读取到的字符串长度合适就去掉换行符然后存入，如果不合适就提示用户重新输入；
    */

    int i = 0;
    while (i < LIM && printf("getting the %d string\n", i + 1) &&
           fgets(ar[i], STRLEN, stdin)) {
        int j = 0;
        while (ar[i][j] != '\n' && ar[i][j] != '\0') { // 找到最后的字符的位置
            printf("%c\n", ar[i][j]);
            j++;
        }

        if (ar[i][j] == '\0') {
            printf("input is too long, try again\n");
            while (getchar() != '\n')
                continue;
        } else {
            ar[i][j] = '\0';
            i++;
        }
    }
}
void printstr(char arr[][STRLEN], int n) {
    for (int i = 0; i < n; i++) {
        puts(arr[i]);
    }
}