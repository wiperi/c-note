// 6.设计一个位字段结构以储存下面的信息。
// 字体ID：0～255之间的一个数；
// 字体大小：0～127之间的一个数；
// 对齐：0～2之间的一个数，表示左对齐、居中、右对齐；
// 加粗：开（1）或闭（0）；
// 斜体：开（1）或闭（0）；
// 在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改
// 变参数。例如，该程序的一个运行示例如下：

#include <stdbool.h>
#include <stdio.h>

#define ALIGN_LEFT 0
#define ALIGN_MIDDLE 1
#define ALIGN_RIGHT 2

const char* align[3] = {"left", "middle", "right"};

struct Setting {
    unsigned int id : 8;
    unsigned int font_size : 7;
    unsigned int : 1;
    unsigned int align : 2;
    bool bold : 1;
    bool italic : 1;
    bool under_line : 1;
};

void show_setting(struct Setting* setting) {

    printf("ID  SIZE ALIGNMENT  B  I  U\n");

    printf("%3d", setting->id);
    printf("%5d", setting->font_size);
    printf("%10s", align[setting->align]);
    printf("%3s", setting->bold == 1 ? "on" : "off");
    printf("%3s", setting->italic == 1 ? "on" : "off");
    printf("%3s", setting->under_line == 1 ? "on" : "off");
    printf("\n");
}

void show_menu() {
    printf("f)change font    s)change size   a)change alignment\n");
    printf("b)toggle bold    i)toggle italic   u)toggle underline\n");
    printf("q)quit\n");
}

int main(int argc, char* argv[]) {

    // create original setting
    struct Setting setting = {234, 125, ALIGN_LEFT, 1, 1, 1};
    show_setting(&setting);

    // main loop
    int ch = 0;
    show_menu();
    while ((scanf(" %c", &ch) == 1 && ch != 'q')) {

        switch (ch) {
        case 'f':
            printf("Enter new font id (0 - 255): ");
            int new_font_id = 0;
            scanf(" %d", &new_font_id);
            if (new_font_id < 0 || new_font_id > 255) {
                printf("invalid font id.\n");
                break;
            }
            setting.id = new_font_id;
            break;
        case 's':
            printf("Enter font size (0 - 127): ");
            int new_font_size = 0;
            scanf(" %d", &new_font_size);

            if (new_font_size < 0 || new_font_size > 127) {
                printf("invalid font size.\n");
                break;
            }
            setting.font_size = new_font_size;
            break;
        case 'a':
            printf("Select alignment:\n");
            printf("0) left  1) middle  2) right\n");
            int new_align = 0;
            scanf(" %d", &new_align);
            if (new_align < 0 || new_align > 2) {
                printf("invalid alignment.\n");
                break;
            }
            setting.align = new_align;
            break;
        case 'b':
            printf("Toggle bold.\n");
            setting.bold ^= 1;
            break;
        case 'i':
            printf("Toggle italic.\n");
            setting.italic ^= 1;
            break;
        case 'u':
            printf("Toggle underline.\n");
            setting.under_line ^= 1;
            break;
        default:
            printf("%c is an invalid command.\n", ch);
            break;
        }

        printf("\n");
        show_setting(&setting);
        show_menu();
    }
}