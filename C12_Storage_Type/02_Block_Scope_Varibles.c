// hiding.c
// 块作用域变量，如果块中的变量和外部变量同名，编译器在处理块中的指令时，块作用域中的变量将“隐藏”外部作用域中的同
// 名变量
#include <stdio.h>
int main() {
    int x = 30; // 创建原始 x
    printf("x in outer block: %d at %p\n", x, &x);

    // 自定义一个块
    {
        int x = 77; // 创建新的 x，它在它的作用域，也就是这个块中，将一直隐藏原始的 x
        printf("x in inner block: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x); // 在自定义块的外面，原始 x 不再被隐藏，打印的是原始 x 的值

    while (x++ < 33) // 此处为原始 x
    
    // while循环语句的循环块
    {
        int x = 100;   // 创建新的 x，隐藏了原始的 x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);
    return 0;
}