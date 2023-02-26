# include <stdio.h>
void sm(void);

int main(void)
{
    for(int n=8;n>=1;n--)
    {
        for(int i=1;i<=n;i++)
        {
           sm();
        }

        printf("\n");
    }

    return 0;
}

void sm(void)
{
    printf("Smile!");
}