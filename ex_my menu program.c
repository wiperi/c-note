#include <stdio.h>
int check_input_and_return(void);
int main(void) {
    int num;
    while ((num = check_input_and_return()) != 666) {
        switch (num) {
            case 1:  // Give me some beer
                printf(
                    "Got it!\n"
                    "Making...\n"
                    "Here, take your beer\n");
                break;
            case 2:  // Book a room
                printf(
                    "What kind of room do you want?\n"
                    "It is 30$ per night.\n"
                    "Ok, Here is your room card, sir.\n");
                break;
            case 3:  // Robbery
                printf(
                    "This is a robbery now get down on the floor!\n"
                    "We here for all the shit that you don't need no more. "
                    "Yeah!\n");
                break;
            default:
                printf("Error! Program crash!\n");
        }
    }
    printf("Bye!\n");
}

int check_input_and_return(void) {
    int input;
    char ch;
    printf(
        "\n\nWelcome to Lunatic Dwarf, the madest bar in the galaxy. What would you like?\n"
        "(Input a number to select...)\n"
        "1:Give me some beer\n"
        "2:Book a room\n"
        "3:Robbery\n");
    while (!(scanf("%d", &input) == 1 && ((input >= 1 && input <= 3) || input == 666))) {  // 本程序的精髓所在
        while ((ch = getchar()) != '\n') putchar(ch); // 将本行输入包括最后的换行符全部消耗掉并输出
        printf(
            " can't be recognized or is not defined. Please input other "
            "intgers like\n");
    }

    /*
    当输入正确时，丢弃当前行的剩余字符

    原因：假如输入：'\n'' '' '' ''\n''2''a''\n'。scanf会跳过空格和换行符，读取2，然后读取a再把a放回输入缓冲，下一次调用scanf会读取a
    */
    while (getchar() != '\n') continue;
    return input;
}