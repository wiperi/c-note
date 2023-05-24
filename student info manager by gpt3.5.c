#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个结构体表示链表节点
struct student {
    char name[50];
    int id;
    int age;
    char sex;
    struct student *next;
};

// 添加一个学生到链表中
void add_student(struct student **head) {
    struct student *new_node, *p;
    new_node = (struct student*) malloc(sizeof(struct student)); // 新建一个结构体，存储新添加的学生信息

    printf("\n请输入学生姓名：");
    scanf("%s", new_node->name);
    printf("请输入学生ID：");
    scanf("%d", &new_node->id);
    printf("请输入学生年龄：");
    scanf("%d", &new_node->age);
    printf("请输入学生性别（M/F）：");
    scanf(" %c", &new_node->sex);

    new_node->next = NULL;

    if (*head == NULL) { // 如果链表为空，将新节点设置为头节点
        *head = new_node;
    } else { // 如果链表不为空，将新节点添加到链表尾部
        p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }

    printf("学生信息添加成功！\n");
}

// 从链表中删除一个学生
void delete_student(struct student **head) {
    int id;
    struct student *p, *q;
    if (*head == NULL) { // 如果链表为空，无法删除
        printf("链表为空，无法删除学生信息！\n");
        return;
    }

    printf("\n请输入要删除的学生ID：");
    scanf("%d", &id);

    p = *head;
    if (p->id == id) { // 如果要删除的学生是头节点，直接删除头节点
        *head = p->next;
        free(p);
        printf("学生信息删除成功！\n");
        return;
    }

    while (p != NULL && p->id != id) { // 在链表中查找要删除的学生
        q = p;
        p = p->next;
    }

    if (p == NULL) { // 如果未找到要删除的学生，提示未找到
        printf("未找到要删除的学生信息！\n");
        return;
    }

    q->next = p->next; // 如果找到要删除的学生，将该学生从链表中删除
    free(p);
    printf("学生信息删除成功！\n");
}

// 查询某一名学生的全部信息
void search_student(struct student *head) {
    int id;
    struct student *p;
    if (head == NULL) { // 如果链表为空，无法查询
        printf("链表为空，无法查询学生信息！\n");
        return;
    }

    printf("\n请输入要查询的学生ID：");
    scanf("%d", &id);

    p = head;
    while (p != NULL && p->id != id) { // 在链表中查找要查询的学生
        p = p->next;
    }

    if (p == NULL) { // 如果未找到要查询的学生，提示未找到
        printf("未找到要查询的学生信息！\n");
        return;
    }

    // 如果找到要查询的学生，输出该学生的所有信息
    printf("\n学生姓名：%s\n", p->name);
    printf("学生ID：%d\n", p->id);
    printf("学生年龄：%d\n", p->age);
    printf("学生性别：%c\n", p->sex);
}

// 打印所有学生的姓名
void print_students(struct student *head) {
    struct student *p;
    if (head == NULL) {
        printf("链表为空，无法打印学生信息！\n");
        return;
    }

    p = head;
    printf("\n所有学生的姓名如下：\n");
    while (p != NULL) {
        printf("%s\n", p->name);
        p = p->next;
    }
}

// 打印学生总数
void print_count(struct student *head) {
    int count = 0;
    struct student *p;
    p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    printf("\n当前学生总数为：%d\n", count);
}

int main() {
    struct student *head = NULL;
    int choice;

    do {
        printf("\n\n*** 学生信息管理系统 ***\n");
        printf("1. 查询某一名学生的全部信息\n");
        printf("2. 打印所有学生的姓名\n");
        printf("3. 添加一名学生\n");
        printf("4. 删除一名学生\n");
        printf("0. 退出程序\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                search_student(head);
                break;
            case 2:
                print_students(head);
                break;
            case 3:
                add_student(&head);
                break;
            case 4:
                delete_student(&head);
                break;
            case 0:
                printf("程序已退出！\n");
                break;
            default:
                printf("输入有误，请重新选择！\n");
                break;
        }

        print_count(head);
    } while (choice != 0);

    return 0;
}