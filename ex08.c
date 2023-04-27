/*
8.编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得
用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的
操作。该程序只接受菜单提供的选项。程序使用float类型的变量储存用户输
入的数字，如果用户输入失败，则允许再次输入。进行除法运算时，如果用
户输入0作为第2个数（除数），程序应提示用户重新输入一个新值。该程序
的一个运行示例如下：
Enter the operation of your choice:
a. add s. subtract
m. multiply d. divide
q. quit

a

Enter first number: 22 .4
Enter second number: one
one is not an number.
Please enter a number, such as 2.5, -1.78E8, or 3: 1
22.4 + 1 = 23.4

Enter the operation of your choice:
a. add s. subtract
m. multiply d. divide
q. quit

d

Enter first number: 18.4
Enter second number: 0
Enter a number other than 0: 0.2
18.4 / 0.2 = 92
Enter the operation of your choice:
a. add s. subtract
m. multiply d. divide
q. quit

q

Bye.
*/
#include <stdio.h>
char get_and_check_the_choice();
float check_input_and_return(void);
int main(void) {
    float first_num, second_num;
    char choice;
    while ((choice = get_and_check_the_choice()) != 'q') {
        switch (choice) {
            case 'a':  // add
                printf("??? + float\n");
                first_num = check_input_and_return();
                printf("%.2f + ???\n", first_num);
                second_num = check_input_and_return();
                printf("%.2f + %.2f = %.2f\n", first_num, second_num,
                       first_num + second_num);
                break;
            case 's':  // substract
                printf("??? - float\n");
                first_num = check_input_and_return();
                printf("%.2f - ???\n", first_num);
                second_num = check_input_and_return();
                printf("%.2f - %.2f = %.2f\n", first_num, second_num,
                       first_num - second_num);
                break;
            case 'm':  // multiply
                printf("??? * float\n");
                first_num = check_input_and_return();
                printf("%.2f * ???\n", first_num);
                second_num = check_input_and_return();
                printf("%.2f * %.2f = %.2f\n", first_num, second_num,
                       first_num * second_num);
                break;
            case 'd':  // divide
                printf("??? / flaot\n");
                first_num = check_input_and_return();
                printf("%.2f / ???\n", first_num);
                second_num = check_input_and_return();
                printf("%.2f / %.2f = %.2f\n", first_num, second_num,
                       first_num / second_num);
                break;
            default:
                printf("Trigger default selction. Error!\n");
        }
    }
    printf("Bye.\n");
}

char get_and_check_the_choice() {
    char input, ch;
    printf(
        "\n\nEnter the operation of your choice:\n"
        "a. add s. subtract\n"
        "m. multiply d. divide\n"
        "q. quit\n");
    while ((scanf("%c", &input) != 1) ||
           (input != 'a' && input != 's' && input != 'm' && input != 'd')) {
        if (input != ' ') {
            while ((ch = getchar()) != '\n') {
                putchar(ch);
            }
            printf(" is not a optional choice. Please input again...\n");
        } 
        else {
            printf("'\\n' is not a optional choice. Please input again...\n");
        }
    }
    while (getchar() != '\n') continue;
    return input;
}

float check_input_and_return(void) {
    float input;
    char ch;
    while ((scanf("%f", &input) != 1)) {
        while ((ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not a flaoting point number. Input again...\n");
    }
    while (getchar() != '\n') continue;
    return input;
}