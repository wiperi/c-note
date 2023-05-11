/**
 * 读取字符串，将字符串排序，打印字符串
 *
 * 读取字符串：编写一个函数，如果limit是n个字符，那么就进行读取n个元素，丢弃换行符
 */
#include <stdio.h>
#define STRLEN 5
#define LIM 5

/**
 * 读取字符串然后写入指定的数组中，当读取次数小于限制 且 当没有读取到换行符
 * 的时候，将读取到的字符写入数组中； 之后，会有两种情况：
 *     1，数组末尾元素是'\0'，字符串长度合适，返回地址
 *     2，数组末尾元素是其他字符，字符串长度过长，将所有元素替换为空字符，清空输入，返回空指针
 *
 * 参数：
 *     将读取到的字符串写入该地址
 *     限制字符数
 * 返回值：
 *     如果读取的字符串合适，则返回其地址。
 *     如果不合适，返回空指针
 */
char* GetString(char* arr, int strlen) {
    int i = 0;
    char buffer;
    while (i < strlen && (buffer = getchar()) != '\n') {
        arr[i] = buffer;
        i++;
    }
    if (arr[strlen - 1] == '\0') {
        return arr;
    } else { // 数组末尾元素 == 其他字符的时候
        for (int i = 0; i < strlen; i++) {
            arr[i] = '\0';
        }
        while (getchar() != '\n')
            continue;
        return NULL;
    }
}

/**
 * 该函数打印字符串
 *
 * 参数：
 *     arg1：要打印的字符串数组的地址
 *     arg2：要打印几次
 * 返回值：
 *     空
 */
void PrintStringArray(const char arr[][STRLEN], int print_times) {
    for (int i = 0; i < print_times; i++) {
        puts(arr[i]);
    }
}

int main(void) {

    // 声明字符数组时如果不初始化，那么元素的值将是未定义的。一旦对字符数组进行初始化，未被使用的值将全部被初始化为空字符
    char words[LIM][STRLEN] = {{'\0'}};

    int i = 0;
    while (i < LIM) {
        if (GetString(words[i], STRLEN)) {
            i++;
        } else { // Getstring返回空指针
            puts("input failed, try again");
            continue;
        }
    }
    PrintStringArray(words, LIM);
}
