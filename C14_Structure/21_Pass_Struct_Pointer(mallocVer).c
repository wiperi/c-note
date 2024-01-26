// names3.c -- 使用指针和 malloc()
/**
 * 在结构体内部使用字符指针来存储字符串，这样字符串实际存储在堆内存中
*/
#include <stdio.h>
#include <stdlib.h> // 提供 malloc()、free() 的原型
#include <string.h> // 提供 strcpy()、strlen() 的原型
#define SLEN 81

struct name {
    char* fname; // 使用指针
    char* lname;
    int letters;
};

void getinfo(struct name*); // 分配内存
void makeinfo(struct name*);
void showinfo(const struct name*);
void cleanup(struct name*); // 调用该函数时释放内存
char* s_gets(char* st, int n);

int main(void) {
    struct name person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}

void getinfo(struct name* pt) {
    char temp[SLEN];
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN); // 分配内存以储存名字
    pt->fname = (char*)malloc(strlen(temp) + 1); // 把名拷贝到动态分配的内存中
    strcpy(pt->fname, temp);
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pt->lname = (char*)malloc(strlen(temp) + 1);
    strcpy(pt->lname, temp);
}

void makeinfo(struct name* pt) {
    pt->letters = strlen(pt->fname) + strlen(pt->lname);
}

void showinfo(const struct name* pt) {
    printf("%s %s, your name contains %d letters.\n", pt->fname, pt->lname,
           pt->letters);
}

void cleanup(struct name* pt) {
    free(pt->fname);
    free(pt->lname);
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
                continue; // 处理输入行的剩余部分
    }
    return ret_val;
}