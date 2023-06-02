/* 题目：学生信息管理系统

创建一个简单的学生信息管理系统，其中包含学生的学号、姓名和成绩。请使用结构体、结构体指针
以及将结构体和结构体指针作为参数的函数来实现以下功能：

1. 添加学生的信息。
2. 根据学号查找学生的信息。
3. 更新学生的信息。
4. 显示所有学生的信息。

要求：

1. 定义一个结构体 `Student`，包含学号（整数）、姓名（字符数组）和成绩（浮点数）。
2. 创建一个 `Student` 类型的数组，用于存储学生信息。
3. 编写一个函数 `addStudent`，接受一个结构体 `Student` 作为参数，将学生信息添加到数组中。
4. 编写一个函数 `findStudent`，接受一个整数（学号）和一个结构体指针 `Student *` 作为参数，查找并返回学生信息。
5. 编写一个函数 `updateStudent`，接受一个结构体 `Student` 作为参数，根据学号更新学生的信息。
6. 编写一个函数 `displayStudents`，接受一个结构体指针 `Student *` 和数组的长度作为参数，显示所有学生的信息。

注意：为简化代码，可以假定学生人数不超过100人，且学号是唯一的。 */

#define MAXSTUDENT 100
#define STRLEN 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[STRLEN];
    double grade;
};
char* getstr(char* str, int length) {
    fgets(str, length, stdin);
    char* find = strchr(str, '\n');
    if (find) {
        *find = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return str;
}
struct Student addStudent(struct Student object) {
    printf("Input ID.\n");
    scanf("%d", &object.id);
    while (getchar() != '\n');

    printf("Input name.\n");
    getstr(object.name, STRLEN);

    printf("Input grade.\n");
    scanf("%lf", &object.grade);
    while (getchar() != '\n');

    return object;
}
void findStudent(struct Student* ptr, int id) {
    for (int i = 0; i < MAXSTUDENT; i++) {
        if (ptr[i].id == id) {
            printf("student exist!\n");
        }
    }
    printf("student doesn't exist.\n");
}
struct Student updateStudent(struct Student object) {
    printf("update ID.\n");
    scanf("%d", &object.id);
    while (getchar() != '\n');

    printf("update name.\n");
    getstr(object.name, STRLEN);

    printf("update grade.\n");
    scanf("%lf", &object.grade);
    while (getchar() != '\n');

    return object;
}
void displayStudent(struct Student* ptr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("********************\n");
        printf("name: %s\n", ptr[i].name);
        printf("id: %d\n", ptr[i].id);
        printf("grade: %f\n", ptr[i].grade);
        printf("********************\n");
    }
}

int main(void) {
    struct Student kids[MAXSTUDENT];

    kids[0] = addStudent(kids[0]);
    displayStudent(kids, MAXSTUDENT);

    getchar();

    int choice;
    printf("Select a choice\n");
    while (scanf("%d", &choice)) {
        switch (choice) {
        case '1':
            /* code */
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            /* code */
            break;        
        default:
            break;
        }
    }

}