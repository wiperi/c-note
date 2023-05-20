// hiding.c
// 块作用域变量，如果块中的变量和外部变量同名，编译器在处理块中的指令时，块作用域中的变量将“隐藏”外部作用域中的同
// 名变量
#include <stdio.h>
int main() {
    int x = 30; // 原始的 x
    printf("x in outer block: %d at %p\n", x, &x);

    {
        int x = 77; // 新的 x，隐藏了原始的 x
        printf("x in inner block: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);

    while (x++ < 33) { // 原始的 x
        int x = 100;   // 新的 x，隐藏了原始的 x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);
    return 0;
}