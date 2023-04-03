/*
指针和多维数组
*/
#include <stdio.h>

int main() {
    int aa[2][3] = {{1,2,3},{4,5,6}};

    printf("first it is address\n\n");

    for(int i=0;i<2;i++)
    {
        for(int k=0;k<3;k++)
        {
            printf("%p\n", &aa[i][k]);
        }
    }
    
    printf("\n");
    
    for(int i=0;i<2;i++)
    {
        printf("%p\n", &aa[i]);
    }
    
    printf("\n");
    
    printf("%p\n", &aa);
    
    
    printf("\nthen it is value\n\n");
    
    for(int i=0;i<2;i++)
    {
        for(int k=0;k<3;k++)
        {
            printf("%p\n", aa[i][k]);
        }
    }
    
    printf("\n");
    
    for(int i=0;i<2;i++)
    {
        printf("%p\n", aa[i]);
    }
    
    printf("\n");
    
    printf("%p\n", aa);
    
    
    return 0;
}