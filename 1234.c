#include <stdio.h>
char get_choice(void);
void count(void);
int main(void) {
    int choice;
    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high.\n");
                break;
            case 'b':
                putchar('\a'); /* ANSI */
                break;
            case 'c':
                count();
                break;
            default:
                printf("Program error!\n");
                break;
        }
    }
    return 0;
}
