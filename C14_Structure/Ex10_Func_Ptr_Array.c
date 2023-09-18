/* 10.编写一个程序，通过一个函数指针数组实现菜单。例如，选择菜单
中的 a，将激活由该数组第 1个元素指向的函数。 */

#include <stdio.h>

void func_1(void) {
    puts("This is the function 1 your selected");
}
void func_2(void) {
    puts("This is the function 2 your selected");
}
void func_3(void) {
    puts("This is the function 3 your selected");
}
void func_4(void) {
    puts("This is the function 4 your selected");
}

int main(void) {
    void (*pfar[4])(void) = {func_1, func_2, func_3, func_4};

    int choice;
    do {
        puts("Choice your selection.");
        puts("(1) func1 (2) func2 (3) func3 (4) func4 (0)quit");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            pfar[choice]();
            break;
        case 2:
            pfar[choice]();
            break;
        case 3:
            pfar[choice]();
            break;
        case 4:
            pfar[choice]();
            break;
        default:
            puts("default triggered! error!");
            break;
        }
    } while (choice != 0);
}