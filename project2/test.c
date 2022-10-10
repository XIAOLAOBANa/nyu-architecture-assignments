#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void)
{
    float value;
    scanf("%f", &value);
    printf("%x\n", *(int*)(&value));
    // const char * str1 = "park";
    // const char * str2 = "sark";
    // int flag = strcmp(str1, str2);
    // float a = 0x3f800001;
    return 0;
}