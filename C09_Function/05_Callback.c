/**
 * 回调（callback），意思是将函数作为参数传递给另一个函数，在特定的条件下执行该函数。
 *
 * 该程序演示了回调的使用案例，强尼是一名阿尔伯开克的小混混，每天在街头从事某些活动来
 * 充实自己的银行账户，随时有概率被条子抓到，强尼有几张名片，他知道如果别条子抓到就靠
 * 这拨打这些名片上的电话。
 */

#define STRLEN 80
#include <stdio.h>
#include <stdlib.h>

// 强尼的银行账户存款
int AccountBalance = 0;

// 这是一张名片，强尼一直戴在身上，以备不时之需
void BetterCallSaul(char name[STRLEN]) {
    printf("Calling Saul...");

    printf("Hei! Is this Saul Goodman?\n"
           "The lawyer guy?\n"
           "Oh, my name is %s, I am in troubel now.\n"
           "I need your help!\n", name);
}

// 这是一张名片，强尼一直戴在身上，以备不时之需
void CallKimWestler(char name[STRLEN]) {
    printf("Calling Kim...");

    printf("Hei! Is this Kim Westler?\n"
           "The lawyer?\n"
           "Oh, my name is %s, I am in troubel now.\n"
           "I need your help!\n", name);
}

// 强尼每次得手就去银行把赃款存入账户
void MakingDeposit(int amount) {
    AccountBalance += amount;
}

// 强尼在街头游荡，每一次行动都有几率被警察抓到
void JonnyIsHavingFunIntheABK(void (*CallSomeBody)(char name[STRLEN])) {

    // 强尼在从事第一项活动
    printf("Jonny is dealing drugs...\n");
    if (rand() % 100 < 33) {
        printf("Jonny getting caught...\n");
        CallSomeBody("Jonny");
    }
    MakingDeposit(rand() % 400 - 100);

    // 强尼在从事第二项活动
    printf("Jonny is peeing on the street...\n");
    if (rand() % 100 < 33) {
        printf("Jonny getting caught...\n");
        CallSomeBody("Jonny");
    }
    MakingDeposit(rand() % 400 - 100);

    // 强尼在从事第三项活动
    printf("Jonny is shotting another ganger...\n");
    if (rand() % 100 < 99) {
        printf("Jonny getting caught...\n");
        CallSomeBody("Jonny");
    }
    MakingDeposit(rand() % 5000 - 100);
}

int main(void) {

    time_t t;
    srand((unsigned int) time(&t));

    // 强尼有50%的几率打给Saul或者Kim
    if (rand() % 100 < 50) {
        JonnyIsHavingFunIntheABK(BetterCallSaul);
    } else {
        JonnyIsHavingFunIntheABK(CallKimWestler);
    }

    printf("There is %d left in Jonny's account.\n", AccountBalance);
}