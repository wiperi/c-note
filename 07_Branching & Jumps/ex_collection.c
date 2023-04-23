#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
void ex_1(void) {
    /*
    1.编写一个程序读取输入，读到#字符停止，然后报告读取的空格数、
    换行符数和所有其他字符的数量。
    */
    char input_ch;
    int space = 0, enter = 0, other_ch = 0;
    while ((input_ch = getchar()) != '#') {
        if (input_ch == ' ') space += 1;
        if (input_ch == '\n')
            enter += 1;
        else
            other_ch += 1;
    }
    printf("space = %d\n", space);
    printf("enter = %d\n", enter);
    printf("other_ch = %d\n", other_ch);
}
void ex_2(void) {
    /*
    2.编写一个程序读取输入，读到#字符停止。程序要打印每个输入的字
    符以及对应的ASCII码（十进制）。一行打印8个字符。建议:使用字符计数
    和求模运算符（%）在每8个循环周期时打印一个换行符。
    */
    char input;
    int ch_count = 0;
    while ((input = getchar()) != '#') {
        ch_count += 1;
        if (ch_count % 8 != 0)
            printf("%c %d, ", input, input);
        else
            printf("%c %d\n", input, input);
    }
}
void ex_9() {
    /*
    9.编写一个程序，只接受正整数输入，然后显示所有小于或等于该数的
    素数。
    */
    int num;
    while (scanf("%d", &num) && num > 0) {
        for (int i = 2; i <= num; i++) {
            bool isprime = true;
            
            /*
            下面for循环的判定条件使用了简化的方法判定一个数字是不是质数：

            这里的数学原理基于以下事实：如果 n 是一个合数（即非
            素数），那么它必定可以表示为两个正整数 a 和 b 的乘积
            ，即 n = a * b。根据算术性质，a 和 b 中至少有一个数
            不大于 n 的平方根。换句话说，如果我们在 2 到 sqrt(n)
            之间找不到一个可以整除 n 的数，那么 n 就是一个素数。

            这就是为什么我们只需要检查 2 到 sqrt(n) 之间的整数是
            否能整除 n。在循环中，我们使用了 i * i <= n 作为循环
            条件，这等价于 i <= sqrt(n)，但避免了使用浮点数计算。
            */
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isprime = false;
                    break;
                }
            }
            if (isprime) printf("%d, ", i);
        }
    }
}
int main(void) { ex_9(); }