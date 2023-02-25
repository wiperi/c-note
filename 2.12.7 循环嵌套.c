/*
7.许多研究表明，微笑益处多多。编写一个程序，生成以下格式的输
出：
Smile!Smile!Smile!
Smile!Smile!
Smile!
该程序要定义一个函数，该函数被调用一次打印一次“Smile!”，根据程
序的需要使用该函数。
*/
#include <stdio.h>
void sm(void);

int main()
{
    int t=3;
    int n;
    for(int i=1;i<=3;i++)
    {
        n=t;
        while(n>=1)
        {
            sm();
            n=n-1;
        }
        t=t-1;
    }
    
    return 0;
}

void sm(void)
{
    printf("Smile!");
}