#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(int x){
    
    if (x < 0) {
        return false;
    }

    // transfer x into a char string
    char* buffer = (char*)malloc(sizeof(char) * 4);
    sprintf(buffer, "%d", x);

    // find the index of last char
    unsigned short end = 0;
    while (buffer[end] != '\0') {
        end++;
    }
    end = end - 1;

    // compare the buffer[end] and buffer[0] for serveral times
    for (unsigned short i = 0; i < ((end + 1)/2); i++) {
        if (buffer[end - i] != buffer[i]) {
            return false;
        }
    }
    return true;
    free(buffer);
}

int main(void) {
    printf("%d", isPalindrome(142341));
}