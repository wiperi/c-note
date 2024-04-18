#include <limits.h>
#include <stdio.h>

char* itobs(int, char*);
void show_bstr(const char*);
int invert_end(int num, int bits);

int main(void) {
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    
    while (scanf("%d", &number) == 1) {

        itobs(number, bin_str);
        printf("%d is\n", number);

        show_bstr(bin_str);
        putchar('\n');
        
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }

    puts("Bye!");
    return 0;
}

char* itobs(int n, char* ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';
    return ps;
}

/* 以4位为一组，显示二进制字符串 */
void show_bstr(const char* str) {
    int i = 0;
    while (str[i]) /* 不是空字符 */
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

/**
 * Inverts the last 'bits' number of bits in the given 'num'.
 *
 * @param num The number whose bits need to be inverted.
 * @param bits The number of bits to be inverted from the end of 'num'.
 * @return The resulting number after inverting the specified bits.
 */
int invert_end(int num, int bits) {
    int mask = 0;
    int bitval = 1;
    while (bits-- > 0) {
        mask |= bitval;
        bitval <<= 1;
    }
    return num ^ mask;
}