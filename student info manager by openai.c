#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生类
typedef struct {
    char name[100];
    int id;
    int age;
    char gender;
} Student;

// 学生管理类
typedef struct {
    Student** students;
    int count;
} StudentManager;

// 创建学生
Student* createStudent(char name[100], int id, int age, char gender) {
    // 为学生分配内存空间
    Student* student = (Student*)malloc(sizeof(Student));
    if (student == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    // 复制学生信息
    strcpy(student->name, name);
    student->id = id;
    student->age = age;
    student->gender = gender;
    
    return student;
}

// 创建学生管理器
StudentManager* createStudentManager() {
    // 为学生管理器分配内存空间
    StudentManager* manager = (StudentManager*)malloc(sizeof(StudentManager));
    if (manager == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    // 初始化学生管理器
    manager->students = NULL;
    manager->count = 0;
    
    return manager;
}

// 销毁学生管理器
void destroyStudentManager(StudentManager* manager) {
    if (manager == NULL) {
        return;
    }
    
    // 释放每个学生的内存
    for (int i = 0; i < manager->count; i++) {
        free(manager->students[i]);
    }
    
    // 释放学生管理器内存
    free(manager);
}

// 添加学生
void addStudent(StudentManager* manager, Student* student) {
    // 分配更多的内存以容纳新学生
    manager->students = (Student**)realloc(manager->students, (manager->count + 1) * sizeof(Student*));
    if (manager->students == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    // 添加学生到学生管理器
    manager->students[manager->count] = student;
    manager->count++;
}

// 删除学生
void deleteStudent(StudentManager* manager, int id) {
    int index = -1;
    
    // 查找学生在学生管理器中的位置
    for (int i = 0; i < manager->count; i++) {
        if (manager->students[i]->id == id) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        // 释放学生内存
        free(manager->students[index]);
        
        // 将后面的学生前移
        for (int i = index; i < manager->count - 1; i++) {
            manager->students[i] = manager->students[i + 1];
        }
        
        // 缩小内存空间以适应新的学生数量
        manager->students = (Student**)realloc(manager->students, (manager->count - 1) * sizeof(Student*));
        if (manager->students == NULL && manager->count > 1) {
            printf("内存分配失败\n");
            exit(1);
        }
        
        manager->count--;
    } else {
        printf("未找到指定的学生\n");
    }
}

// 查询学生信息
void queryStudent(StudentManager* manager, int id) {
    int index = -1;
    
    // 查找学生在学生管理器中的位置
    for (int i = 0; i < manager->count; i++) {
        if (manager->students[i]->id == id) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        // 打印学生信息
        Student* student = manager->students[index];
        printf("姓名：%s\n", student->name);
        printf("学号：%d\n", student->id);
        printf("年龄：%d\n", student->age);
        printf("性别：%c\n", student->gender);
    } else {
        printf("未找到指定的学生\n");
    }
}

// 打印所有学生的姓名和ID
void printAllStudents(StudentManager* manager) {
    printf("所有学生的姓名和ID：\n");
    for (int i = 0; i < manager->count; i++) {
        printf("姓名：%s，学号：%d\n", manager->students[i]->name, manager->students[i]->id);
    }
}

int main() {
    // 创建学生管理器
    StudentManager* manager = createStudentManager();
    
    int choice;
    
    do {
        // 打印操作选项
        printf("\n学生信息管理系统\n");
        printf("1. 查询学生信息\n");
        printf("2. 打印所有学生的姓名和ID\n");
        printf("3. 添加学生\n");
        printf("4. 删除学生\n");
        printf("0. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // 查询学生信息
                printf("请输入要查询的学生学号：");
                int queryId;
                scanf("%d", &queryId);
                queryStudent(manager, queryId);
                break;
            case 2:
                // 打印所有学生的姓名和ID
                printAllStudents(manager);
                break;
            case 3: {
                // 添加学生
                char name[100];
                int id, age;
                char gender;
                printf("请输入学生姓名：");
                scanf("%s", name);
                printf("请输入学生学号：");
                scanf("%d", &id);
                printf("请输入学生年龄：");
                scanf("%d", &age);
                printf("请输入学生性别（M/F）：");
                scanf(" %c", &gender);  // 注意空格，避免读取上一个输入的换行符
                
                Student* newStudent = createStudent(name, id, age, gender);
                addStudent(manager, newStudent);
                printf("学生添加成功\n");
                break;
            }
            case 4:
                // 删除学生
                printf("请输入要删除的学生学号：");
                int deleteId;
                scanf("%d", &deleteId);
                deleteStudent(manager, deleteId);
                printf("学生删除成功\n");
                break;
            case 0:
                // 退出程序
                break;
            default:
                printf("无效的选择，请重新输入\n");
                break;
        }
        
        // 打印当前学生总数
        printf("当前学生总数：%d\n", manager->count);
        
    } while (choice != 0);
    
    // 销毁学生管理器
    destroyStudentManager(manager);
    
    return 0;
}
