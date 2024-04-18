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

const char* align[3] = {"left", "middle", "right"};

#define ID_MASK 0xff
#define FONT_SIZE_MASK 0x7f00
#define ALIGN_MASK 0x30000
#define BOLD_MASK 0x40000
#define ITALIC_MASK 0x80000
#define UNDER_LINE_MASK 0x100000

void show_setting(unsigned int setting) {

    printf("ID  SIZE ALIGNMENT  B  I  U\n");

    printf("%3d", setting & ID_MASK);
    printf("%5d", setting & FONT_SIZE_MASK);
    printf("%10s", align[(setting & ALIGN_MASK) >> 16]);
    printf("%3s", (setting & BOLD_MASK) != 0 ? "on" : "off");
    printf("%3s", (setting & ITALIC_MASK) != 0 ? "on" : "off");
    printf("%3s", (setting & UNDER_LINE_MASK) != 0 ? "on" : "off");
    printf("\n");
}

void show_menu() {
    printf("f)change font    s)change size   a)change alignment\n");
    printf("b)toggle bold    i)toggle italic   u)toggle underline\n");
    printf("q)quit\n");
}

int main(int argc, char* argv[]) {

    // create original setting
    unsigned int setting = 0;
    show_setting(setting);

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
            setting |= new_font_id;
            break;
        case 's':
            printf("Enter font size (0 - 127): ");
            int new_font_size = 0;
            scanf(" %d", &new_font_size);

            if (new_font_size < 0 || new_font_size > 127) {
                printf("invalid font size.\n");
                break;
            }
            setting |= new_font_size << 8;
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

            // clear the alignment bits
            setting &= ~ALIGN_MASK;
            
            setting |= (new_align << 16);
            break;
        case 'b':
            printf("Toggle bold.\n");
            setting ^= BOLD_MASK;
            break;
        case 'i':
            printf("Toggle italic.\n");
            setting ^= ITALIC_MASK;
            break;
        case 'u':
            printf("Toggle underline.\n");
            setting ^= UNDER_LINE_MASK;
            break;
        default:
            printf("%c is an invalid command.\n", ch);
            break;
        }

        printf("\n");
        show_setting(setting);
        show_menu();
    }
}