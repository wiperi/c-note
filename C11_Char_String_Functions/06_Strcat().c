/* str_cat.c -- 拼接两个字符串 */
/*
strcat()（用于拼接字符串）函数接受两个字符串作为参数。该函数把第
2个字符串的备份附加在第1个字符串末尾，并把拼接后形成的新字符串作为
第1个字符串，第2个字符串不变。strcat()函数的类型是char *（即，指向char
的指针）。strcat()函数返回第1个参数，即拼接第2个字符串后的第1个字符
串的地址。
*/
#include <stdio.h>
#include <string.h> /* strcat()函数的原型在该头文件中 */
#define SIZE 80
char* s_gets(char* st, int n);
int main(void) {
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    puts("What is your favorite flower?");
    if (s_gets(flower, SIZE)) {
        strcat(flower, addon);
        puts("\n\n\n\n");
        puts(flower);
        puts(addon);
    } else
        puts("End of file encountered!");
    puts("bye");
    return 0;
}
char* s_gets(char* st, int n) {
    char* ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n') continue;
    }
    return ret_val;
}
