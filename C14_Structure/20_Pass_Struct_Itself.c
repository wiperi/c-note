/* names2.c -- 传递并返回结构 */
/**
 * 传递结构名的时候，函数获得的是结构体的一份拷贝，函数内部的修改不会影响外部结构体的值
*/
#include <stdio.h>
#include <string.h>
#define NLEN 30

struct name {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct name getinfo(void);
struct name makeinfo(struct name);
void showinfo(struct name);
char* s_gets(char* st, int n);

int main(void) {
    struct name person;
    person = getinfo();
    person = makeinfo(person);
    showinfo(person);
    return 0;
}

struct name getinfo(void) {
    struct name temp;
    printf("Please enter your first name.\n");
    s_gets(temp.fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(temp.lname, NLEN);
    return temp;
}

struct name makeinfo(struct name info) {
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;
}

void showinfo(struct name info) {
    printf("%s %s, your name contains %d letters.\n", info.fname, info.lname, info.letters);
}

char* s_gets(char* st, int n) {
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;
        　　　　　 // 处理输入行的剩余部分
    }
    return ret_val;
}