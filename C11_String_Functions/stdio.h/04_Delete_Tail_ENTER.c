/*
程序清单11.9在程序清单11.8的基础上添加了一部分测试代码。该程序
读取输入行，删除储存在字符串中的换行符，如果没有换行符，则丢弃数组
装不下的字符。
*/
#include <stdio.h>
#define STRLEN 20

int main(void) {
    char word[STRLEN];

    while (fgets(word, STRLEN, stdin) != NULL && word[0] != '\n') {
        int i = 0;
        while (word[i] != '\n' && word[i] != '\0') { // 找到换行符或者空字符所在的位置
            i++;
        }

        if (word[i] == '\n') { // 如果是换行符，说明输入字符串大小未超过上限，则将换行符替换
            word[i] = '\0';
        } else { // 如果是空字符，说明输入字符串大小超过上限了，则丢弃缓冲中未被读取的字符
            while (getchar() != '\n')
                continue;
        }
    }
}