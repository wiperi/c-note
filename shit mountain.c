/* 题目：学生信息管理系统

创建一个简单的学生信息管理系统，其中包含学生的学号、姓名和成绩。请使用结构体、结构体指针
以及将结构体和结构体指针作为参数的函数来实现以下功能：

1. 添加学生的信息。
2. 根据学号查找学生的信息。
3. 更新学生的信息。
4. 显示所有学生的信息。

要求：

1. 定义一个结构体
`Student`，包含学号（整数）、姓名（字符数组）和成绩（浮点数）。
2. 创建一个 `Student` 类型的数组，用于存储学生信息。
3. 编写一个函数 `addStudent`，接受一个结构体 `Student`
作为参数，将学生信息添加到数组中。
4. 编写一个函数 `findStudent`，接受一个整数（学号）和一个结构体指针 `Student *`
作为参数，查找并返回学生信息。
5. 编写一个函数 `updateStudent`，接受一个结构体 `Student`
作为参数，根据学号更新学生的信息。
6. 编写一个函数 `displayStudents`，接受一个结构体指针 `Student *`
和数组的长度作为参数，显示所有学生的信息。

注意：为简化代码，可以假定学生人数不超过100人，且学号是唯一的。 */

#define MAXSTUDENT 100
#define STRLEN 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct of a student
struct Student {
    int id;
    char name[STRLEN];
    double grade;
};

// get string function
char* getstr(char* str, int str_limit) {
    fgets(str, str_limit, stdin);
    char* find = strchr(str, '\n');
    if (find) {
        *find = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    return str;
}

// add a student
struct Student addStudent(struct Student student, int id, char* name,
                          double grade) {
    student.id = id;
    strcpy(student.name, name);
    student.grade = grade;
}

// find a student
void findStudent(struct Student* ptr, int id) {
    if (ptr->id == id) {
        printf("student exist!\n");
    } else {
        printf("student doesn't exist.\n");
    }
}

// update a student
struct Student updateStudent(struct Student student) {
    printf("update ID.\n");
    scanf("%d", &student.id);
    while (getchar() != '\n')
        ;

    printf("update name.\n");
    getstr(student.name, STRLEN);

    printf("update grade.\n");
    scanf("%lf", &student.grade);
    while (getchar() != '\n')
        ;

    return student;
}

// print all
void displayStudent(struct Student* student, int count) {
    printf("Start printing...\n");
    for (int i = 0; i < count; i++) {
        printf("id: %d\n", (student + i)->id);
        printf("name: %s\n", (student + i)->name);
        printf("grade: %f\n", (student + i)->grade);
    }
    printf("Printing terminated.\n");
}

int main(void) {

    // create a student array
    struct Student kids[MAXSTUDENT];
    int count = 0;

    int choice;
    do {
        printf("Choice a selection to start.\n");
        printf("1. Print all student's information\n");
        printf("2. Add a student.\n");
        printf("3. Update a student.\n");
        printf("4. Find a student.\n");
        printf("Input '0' to quit.\n");

        scanf("%d", choice);
        switch (choice) {
        case '1':
            displayStudent(kids, count);
            break;
        case '2':
            int id;
            scanf("%d", &id);

            char name[STRLEN];
            scanf("%s", name);

            double grade;
            scanf("%lf", &grade);

            // addStudent function uses strcut as parameter
            count++;
            kids[count] = addStudent(kids[count], id, name, grade);
            break;
        case '3':
            printf("Input the id of wanted student.\n");
            id = 0;
            scanf("%d", &id);

            int index = -1;
            for (int i = 0; i < count; i++) {
                if (kids[i].id == id) {
                    index = i;
                }
                if (index != -1) {
                    kids[index] = updateStudent(kids[index]);
                } else {
                    printf("Search failed.\n");
                }
            }
            break;
        case '4':
            break;
        default:
            break;
        }
    } while (choice != 0);
}