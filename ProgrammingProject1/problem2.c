// implement your program here
#include<stdio.h>

int main(void)
{
    int n;
    int r, g, b;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d, %d, %d", &r, &g, &b);
        if (r < 0 | r > 255 |
            g < 0 | g > 255 |
            b < 0 | b > 255
        )
            printf("INVALID\n");
        else{
            int hex_color = 0;
            hex_color = hex_color | b | (g << 8) | (r << 16);
            if(r == 0)
                if(g == 0)
                    if(b == 0)
                        printf("#000000\n");
                    else
                        printf("#0000%x\n", b);
                else
                    printf("#00%x\n", hex_color);
            else
                printf("#%x\n", hex_color);
        }
    }
    return 0;
}
