/* names1.c -- 使用指向结构的指针 */
/**
 * 传递结构体指针，函数获得的是一个外部结构体的地址，可以直接修改外部结构体的值
*/
#include <stdio.h>
#include <string.h>
#define NLEN 30

struct name {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct name*);
void makeinfo(struct name*);
void showinfo(const struct name*);
char* s_gets(char* st, int n);

int main(void) {
    struct name person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    return 0;
}

void getinfo(struct name* pst) {
    printf("Please enter your first name.\n");
    s_gets(pst->fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(pst->lname, NLEN);
}

void makeinfo(struct name* pst) {
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct name* pst) {
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

char* s_gets(char* st, int n) 1044 {
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        　                              // 查找换行符
            if (find)　　　　　　　　　 // 如果地址不是 NULL,
                * find = '\0';
        　　　　 // 在此处放置一个空字符
            else while (getchar() != '\n') continue;
        　　　　　 // 处理输入行的剩余字符
    }
    return ret_val;
}