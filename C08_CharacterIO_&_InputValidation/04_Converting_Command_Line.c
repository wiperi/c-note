// atoi() converts string to int
// atof() converts string to double
#include <stdio.h>
#include <stdlib.h>

// This program takes command-line arguments and adds them together
int main(int argc, char* argv[]) {
    int i, sum = 0;
    i = 1;
    while (i < argc) {
        sum = sum + atoi(argv[i]); // atoi menas argument to integer
        i = i + 1;
    }
    printf("sum of command-line arguments=%d\n", sum);
}