/* copy3.c -- 使用strncpy() */
#include <stdio.h>
#include <string.h> /* 提供strncpy()的函数原型*/
#define SIZE 40
#define TARGSIZE 7
#define LIM 5
char* s_gets(char* st, int n);
int main(void) {
    char qwords[LIM][TARGSIZE];
    char temp[SIZE];
    int i = 0;
    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE)) {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else {
            
            /* strncpy(target,source,n)把source中的n个字符或空字符之前
             * 的字符（先满足哪个条件就拷贝到何处）拷贝至target中 */
            strncpy(qwords[i], temp, TARGSIZE);
            qwords[i][TARGSIZE - 1] = '\0'; // 将数组中最后一个字符更改为空字符，确保在输入字符串过长的时候不出错
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++) puts(qwords[i]);
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