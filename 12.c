// 学习完以上几个示例，试试如何用一个语句打印以下格式的内容：
// The NAME family just may be $XXX.XX dollars richer!
#include <stdio.h>

int main(void)
{
    int apple = 123;

    printf("%d,%c,%x"
    , apple, apple, apple);

    return 0;
}