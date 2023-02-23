#include <stdio.h>

void butler(void); /* ANSI/ISO C函数原型 */
void apple(void);

void apple(void)
{
    printf("I like apple.\nIt's is delicious and it is also a marvelious firm.");
}

void butler(void) /* 函数定义开始 */
{
    printf("You rang, sir?\n");

    printf("show me your guts!\n");
}

int main(void);

int main(void)
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable DVDs.\n\n\n");
    apple();
    return 0;
}