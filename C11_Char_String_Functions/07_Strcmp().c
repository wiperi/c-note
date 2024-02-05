/* compare.c -- 该程序可以正常运行 */

// strcmp函数比较两个字符串，逐个字符进行比较，将第一个字符串中的字符的ASCII值减去第二个的值，然后是0那就比较下一个字符

#include <stdio.h>
#include <string.h> // strcmp()函数的原型在该头文件中
#define ANSWER "Grant"
#define SIZE 40
char* s_gets(char* st, int n);
int main(void) {
    char try[SIZE];
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (strcmp(try, ANSWER) != 0) { // Can be also written as: while(strcmp(try, ANSWER));
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");
    return 0;
}
char* s_gets(char* st, int n) {
    char* ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else
            while (getchar() != '\n') {
                continue;
            }
    }
    return ret_val;
}
