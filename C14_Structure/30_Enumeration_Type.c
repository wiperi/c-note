/* enum.c -- 使用枚举类型的值 */
#include <stdbool.h> // C99 特性
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 提供 strcmp()、strchr()函数的原型

char* s_gets(char* st, int n);
enum spectrum { red, orange, yellow, green, blue, violet };                     // enum用于将：变量名 映射到 整数
const char* colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};  // 字符串数组用于将：整数 映射到 字符串形式的变量名
#define LEN 30

/**
 * @brief This function prompts the user to enter colors and displays corresponding messages.
 *
 * The function asks the user to enter a color and then checks if the entered color is valid.
 * If the color is valid, it displays a corresponding message. If the color is not valid,
 * it informs the user that it doesn't know about the entered color.
 */
int main(void) {
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;
    puts("Enter a color (empty line to quit):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0') {
        for (color = red; color <= violet; color++) {
            if (strcmp(choice, colors[color]) == 0) {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
            switch (color) {
            case red:
                puts("Roses are red.");
                break;
            case orange:
                puts("Poppies are orange.");
                break;
            case yellow:
                puts("Sunflowers are yellow.");
                break;
            case green:
                puts("Grass is green.");
                break;
            case blue:
                puts("Bluebells are blue.");
                break;
            case violet:
                puts("Violets are violet.");
                break;
            }
        else
            printf("I don't know about the color %s.\n", choice);
        color_is_found = false;
        puts("Next color, please (empty line to quit):");
    }
    puts("Goodbye!");
    return 0;
}

/**
 * @brief Reads a string from the standard input and removes the newline character.
 *
 * This function reads a string from the standard input using fgets() function.
 * It removes the newline character from the string if present.
 * If the newline character is not found, it clears the remaining characters from the input buffer.
 *
 * @param st The character array to store the input string.
 * @param n The maximum number of characters to read.
 * @return A pointer to the input string if successful, NULL otherwise.
 */
char* s_gets(char* st, int n) {
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 清理输入行
    }
    return ret_val;
}