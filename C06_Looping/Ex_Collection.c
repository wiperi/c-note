#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
3.使用嵌套循环，按下面的格式打印字母：
F
FE
FED
FEDC
FEDCB
FEDCBA
*/
void ex_3(void) {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", 65 + 5 - j);
        }
        printf("\n");
    }
}
/*
4.使用嵌套循环，按下面的格式打印字母：
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/
void ex_4(void) {
    int k;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0, k = i; j <= i; j++, k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}
void ex_4a(void) {
    int i, j;
    int a = 0;
    for (i = 0; i <= 5; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", a);
            a++;
        }
        printf("\n");
    }
}
/*
5.编写一个程序，提示用户输入大写字母。使用嵌套循环以下面金字塔
型的格式打印字母：
A
ABA
ABCBA
ABCDCBA
ABCDEDCBA
打印这样的图形，要根据用户输入的字母来决定。例如，上面的图形是
在用户输入E后的打印结果。
*/
void ex_5(void) {
    int i, j, k;
    printf("Inpu a number k to get k rows of pyramid:...\b\b\b");
    scanf("%d", &k);
    for (i = 0; i <= k; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", j);
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", i - j);
        }
        printf("\n");
    }
}
/*
7.编写一个程序把一个单词读入一个字符数组中，然后倒序打印这个单
词。提示：strlen()函数（第4章介绍过）可用于计算数组最后一个字符的下
标。
*/
void ex_7(void) {
    char arr[40];
    scanf("%s", arr);
    for (int i = 0; i < strlen(arr); i++) {
        printf("%c", arr[strlen(arr) - 1 - i]);  // 注意：这里arr[strlen() -
                                                 // 1]才是arr的最后一个元素
    }
}
void ex_10(void) {
    /*
    10.编写一个程序，要求用户输入一个上限整数和一个下限整数，计算
    从上限到下限范围内所有整数的平方和，并显示计算结果。然后程序继续提
    示用户输入上限和下限整数，并显示结果，直到用户输入的上限整数小于下
    限整数为止。
    */
    int top, bottom;
    int total = 0;
    printf("Input the lower bound & upper bound...(Input char to quit)\n");
    while (scanf("%d%d", &bottom, &top) == 2) {
        for (int i = bottom; i <= top; i++) {
            total += i * i;
        }
        printf("The sum of squares = %d\n", total);
        total = 0;  // 将total重置，然后再进行下一次运算
    }
    printf("END\n");
}
void ex_12(void) {  // 计算调和级数和交错调和级数
    /*
    12.考虑下面两个无限序列：
    1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
    1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
    编写一个程序计算这两个无限序列的总和，直到到达某次数。提示：奇
    数个-1 相乘得-1，偶数个-1相乘得1。让用户交互地输入指定的次数，当用
    户输入0或负值时结束输入。查看运行100项、1000项、10000项后的总和，
    是否发现每个序列都收敛于某值？
    */
    int calculation_times;
    while (scanf("%d", &calculation_times) && calculation_times > 0) {
        double addition_sum = 0;  // 每次loop开始前要重置sum的值
        double alternative_sum = 0;
        for (double i = 1; i <= calculation_times; i++) {
            addition_sum += 1 / i;  // 计算第一个无限序列
            if ((int)i % 2 !=
                0) {  // 计算第二个无限序列，注意取余运算符的运算对象只能是整数
                alternative_sum += 1 / i;
            } else {
                alternative_sum -= 1 / i;
            }
        }
        printf("addition_sum = %f\n", addition_sum);
        printf("alternative_sum = %f\n", alternative_sum);
    }
}
void ex_17(void) {
    /*
    17.Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的
    账户。在每年的最后一天， Chuckie取出10万美元。编写一个程序，计算多
    少年后Chuckie会取完账户的钱？
    */
    int year = 1;
    double juice = 100;
    do {
        juice += juice * 0.08;
        juice -= 10;
        printf("Remaining = %f\n", juice);
        year++;
    } while (juice >= 10);
    printf("It take %d years to withdraw all the money", year);
}
int main() { ex_17(); }