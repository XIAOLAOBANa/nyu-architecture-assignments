// implement your program here
#include<stdio.h>

int main(void)
{
    int MM=0, DD=0, hh=0, mm=0, ss=0;
    int n=0;
    // char str[30]={0};
    char MD[6]={0}, time[9]={0};


    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        // scanf("%d/%d %d:%d:%d", MM, DD, hh, mm, ss);
        // scanf("%d/%d", MM, DD);
        // scanf("%s", str);
        scanf("%s %s", MD, time);
        // printf("%s %s\n", MD, time);

        MM = (MD[0]-'0') * 10 + MD[1]-'0';
        DD = (MD[3]-'0') * 10 + MD[4]-'0';
        hh = (time[0]-'0') * 10 + time[1]-'0';
        mm = (time[3]-'0') * 10 + time[4]-'0';
        ss = (time[6]-'0') * 10 + time[7]-'0';
        
        //printf("%s\n", str);
        //printf("%d %d %d %d %d\n", MM, DD, hh, mm, ss);
        int max_d = 0;
        switch (MM)
        {
            case 1:
                max_d = 31;
                break;
            case 2:
                max_d = 28;
                break;
            case 3:
                max_d = 31;
                break;
            case 4:
                max_d = 30;
                break;
            case 5:
                max_d = 31;
                break;
            case 6:
                max_d = 30;
                break;
            case 7:
                max_d = 31;
                break;
            case 8:
                max_d = 31;
                break;
            case 9:
                max_d = 30;
                break;
            case 10:
                max_d = 31;
                break;
            case 11:
                max_d = 30;
                break;
            case 12:
                max_d = 31;
                break;
            default:
                break;
        }

        if (MM > 12 || MM < 0 ||
            DD > max_d || DD < 0 ||
            hh > 24 || hh < 0 ||
            mm > 60 || mm < 0 ||
            ss > 60 || ss < 0
        )
            printf("INVALID\n");
        else{
            unsigned int bits_date = 0;
            bits_date |=  (time[7]-'0');
            bits_date |=  ((time[6]-'0') << 4);
            bits_date |=  ((time[4]-'0') << 7);
            bits_date |=  ((time[3]-'0') << 11);
            bits_date |=  ((time[1]-'0') << 14);
            bits_date |=  ((time[0]-'0') << 18);
            bits_date |=  ((MD[4]-'0') << 20);
            bits_date |=  ((MD[3]-'0') << 24);
            bits_date |=  ((MD[1]-'0') << 26);
            bits_date |=  ((MD[0]-'0') << 30);
            printf("%d\n", bits_date);
        }
    }

    
    


    

    return 0;
}