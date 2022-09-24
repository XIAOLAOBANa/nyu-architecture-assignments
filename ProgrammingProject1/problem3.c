// implement your program here
#include<stdio.h>

int main(void)
{
    int n;
    int a=0, b=0;
    scanf("%d", &n);
    while(n != 0)
    {
        int bit = 1;
        int j = 0;
        int flag[32];
        for(int i=0; i<32; i++)
            flag[i] = -1;
        for(int i=0; i<32; i++)
        {           
            if(n & bit) 
                flag[j++] = i;
            bit <<= 1;   
        }
        int k = 0;
        while( flag[k] != -1)
        {
            if (k % 2)
                b = b | (1 << flag[k]);
            else
                a = a | (1 << flag[k]);
            k++;
        }
        printf("%d %d\n", a, b);
        a = 0;
        b = 0;
        scanf("%d", &n);
    }

    return 0;
}
