#include <stdio.h>
void func(int n);
int main(void) {
    func(67);
}

void func(int n) {
    if ((int)(n / 2) != 0) 
    func(n / 2);
    printf("%d", n % 2);
}