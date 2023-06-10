/* 13.声明4个函数，并初始化一个指向这些函数的指针数组。每个函数都
接受两个double类型的参数，返回double类型的值。另外，用两种方法使用
该数组调用带10.0和2.5实参的第2个函数。 */

#include <math.h>
#include <stdio.h>

double add(double a, double b) {
    return a + b;
}
double sub(double a, double b) {
    return a - b;
}
double multi(double a, double b) {
    return a * b;
}
double divi(double a, double b) {
    return a / b;
}
int main(void) {
    double (*pfar[4])(double, double) = {add, sub, multi, divi};

    double ret_1 = pfar[1](10.0, 2.5);

    double ret_2 = (*pfar[1])(10.0, 2.5);
    
    double ret_3 = (*(pfar + 1))(10.0, 2.5);

    printf("%f\n", ret_1);
    printf("%f\n", ret_2);
    printf("%f\n", ret_3);
}