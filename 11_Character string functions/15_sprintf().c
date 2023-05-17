#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    int num = 42;
    float f = 3.14;
    char str[] = "Hello, world!";

    // 将不同类型的数据格式化为字符串
    sprintf(buffer, "Integer: %d, Float: %.2f, String: %s", num, f, str);

    printf("Formatted string: %s\n", buffer);

    return 0;
}
