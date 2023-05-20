#include <stdio.h>
// 局部静态变量和局部自动变量的区别
int main(void) {
    for (size_t i = 0; i < 3; i++) {

        /**
         * 在for()函数的每次迭代中，该变量都被初始化为1
        */
        int auto_storage_duration_varibles = 1;
        
        printf("%d\n", auto_storage_duration_varibles++);
    }

    for (size_t i = 0; i < 3; i++) {

        /**
         * 这条声明实际上不是for函数的一部分，因为静态变量和外部变量
         * 的声明在程序被载入内存中的时候已经执行完毕。把声明放在for
         * 函数中是告诉编译器该变量的作用域为for函数内部
         */
        static int static_storage_varibles = 1;
        
        printf("%d\n", static_storage_varibles++);
    }
}