#define PR(...) printf(__VA_ARGS__)
#define MULT(a, b) ((a) * (b))

#define MAX 100
#define MIN 0

#include <stdio.h>

int main(void) {
    int a = 10, b = 20;
    
    PR("MAX = %d\n", MAX);
    PR("MIN = %d\n", MIN);
    PR("MULT(%d, %d) = %d\n", a, b, MULT(a, b));
    return 0;
}