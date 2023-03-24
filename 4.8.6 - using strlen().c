/*
4.8.6.编写一个程序，先提示用户输入名，然后提示用户输入姓。在一行打
印用户输入的名和姓，下一行分别打印名和姓的字母数。字母数要与相应名
和姓的结尾对齐，如下所示：
Melissa Honeybee
7 8
接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，
如下所示：
Melissa Honeybee
7 8
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Please input your first name.\n");
    char first_name[40];
    scanf("%s", first_name);

    printf("Please input your last name.\n");
    char last_name[40];
    scanf("%s", last_name);

    printf("\nHit ENTER to get your full name...\n");
    getchar();
    getchar();

    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n", strlen(first_name), strlen(first_name), strlen(last_name), strlen(last_name));

    printf("\nHit ENTER to get another example...\n");
    getchar();

    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d", 1, strlen(first_name), strlen(first_name), strlen(last_name));

    return 0;
}