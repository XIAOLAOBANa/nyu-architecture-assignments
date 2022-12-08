#include <stdio.h>
#include <string.h>
#define LINE_MAX 128

void getdata(char (*tlb)[128], char (*page)[128], char (*cache)[128], int *len);


int main(void)
{
    
    char tlb[LINE_MAX][LINE_MAX];
    char page[LINE_MAX][LINE_MAX];
    char cache[LINE_MAX][LINE_MAX];
    int len[3]={0};

    getdata(tlb, page, cache, len);
    // for(int i=0; i<3; i++)
    //     printf("%d\n", len[i]);

    // for(int j = 0; j<len[0]; j++)
    //     printf("%s\n", tlb[j]);

    // for(int j = 0; j<len[1]; j++)
    //     printf("%s\n", page[j]);

    // for(int j = 0; j<len[2]; j++)
    //     printf("%s\n", cache[j]);
    

    return 0;
}


void getdata(char (*tlb)[128], char (*page)[128], char (*cache)[128], int *len)
{
    char text[LINE_MAX];
    // open the file
    
    FILE *fp = fopen("./Project4Input.txt", "r");
    if(fp == NULL)
    {
        printf("Failed to open file\n");
        return;
    }
    int i=0, j=0, k=0;
    int line_len;
    // put the content to tlb[][], page[][], and cache[][]
    while (fgets(text, LINE_MAX, fp)) 
    {
        line_len = strlen(text);
		// delete '\n' and 空行
		if (text[line_len - 1] == '\n') 
        {
			text[line_len - 1] = '\0';
			line_len--;
			if (0 == line_len) 
				//空行
				continue;
        }
        if (text[0] == 'T')
            strcpy(tlb[i++], text);
        else if (text[0] == 'P')
            strcpy(page[j++], text);
        else if (text[0] == 'C')
            strcpy(cache[k++], text);
    }
    len[0] = i;
    len[1] = j;
    len[2] = k;
    fclose(fp);
    // printf("%s\n", tlb[0]);
}



