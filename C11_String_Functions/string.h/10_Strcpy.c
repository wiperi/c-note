/* copy1.c -- 演示 strcpy() */
#include <stdio.h>
#include <string.h>  // strcpy()的原型在该头文件中
#define SIZE 40
#define LIM 5
char* s_gets(char* st, int n);
int main(void) {
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;
    printf("Enter %d words beginning with q:\n", LIM);

    // 将读取的字符串保存在temp中，检查其首字母是否是q，若是则将temp中的字符串复制qwords中
    while (i < LIM && s_gets(temp, SIZE)) {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else {
            strcpy(qwords[i], temp);
            i++;
        }
    }

    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++) puts(qwords[i]);
    return 0;
}
char* s_gets(char* st, int n) { // 读取一次输入缓冲中的字符，将换行符替换为空字符，并将缓冲中多余字符消耗掉
    char* ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {  // 如果ret_val非0，即ret_val不指向NULL，即fgets()返回值不是NULL，即fgets()读取到了字符串
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n') continue;
    }
    return ret_val;
}