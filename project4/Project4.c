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
    while(1)
    {
        int addr;
        int tlbIndex, tlbTag, VPO, VPN, PPN=0, CTag, CIndex, COffset;
        
        printf("Enter Virtual Address:");
        scanf("%hX", &addr);
        VPO = addr & 0x3f;
        VPN = (addr & 0x3fc0) >> 6;
        tlbIndex = (addr & 0xc0) >> 6;
        tlbTag = (addr & 0x3f00) >> 8;
        // printf("%hx, %hx, %hx, %hx\n", VPN, VPO, tlbIndex, tlbTag);

        int index=0, tag=0;
        for (int i = 0; i < len[0]; i++)
        {
            // 得到tlb每一行的set index | tag | 
            
            if (tlb[i][4] >= '0' && tlb[i][4] <= '9')
                index = tlb[i][4] - '0';
            else
                index = tlb[i][4] - 'A' + 10;

            if (tlb[i][6] >= '0' && tlb[i][6] <= '9')
                tag = (tlb[i][6] - '0') * 16;
            else
                tag = (tlb[i][6] - 'A' + 10) * 16;

            if (tlb[i][7] >= '0' && tlb[i][7] <= '9')
                tag += tlb[i][7] - '0';
            else
                tag += tlb[i][7] - 'A' + 10;

            // TLB命中 计算PPN
            if(index == tlbIndex && tag == tlbTag)
            {
                if (tlb[i][9] >= '0' && tlb[i][9] <= '9')
                    PPN = (tlb[i][9] - '0') * 16;
                else
                    PPN = (tlb[i][9] - 'A' + 10) * 16;

                if (tlb[i][10] >= '0' && tlb[i][10] <= '9')
                    PPN += tlb[i][10] - '0';
                else
                    PPN += tlb[i][10] - 'A' + 10;
                break;
            }
            PPN = -1;
            // tag = 0;
        }
        
        if (PPN < 0)
        {
            //TLB 没命中， 来页表找
            int vpn=0;
            for (int j=0; j<len[1]; j++)
            {
                if (page[j][5] >= '0' && page[j][5] <= '9')
                    vpn = page[j][5] - '0';
                else
                    vpn = page[j][5] - 'A' + 10;
                
                if(vpn == VPN)
                {
                    if (page[j][7] >= '0' && page[j][7] <= '9')
                        PPN = (page[j][7] - '0') * 16;
                    else
                        PPN = (page[j][7] - 'A' + 8) * 16;

                    if (page[j][8] >= '0' && page[j][8] <= '9')
                        PPN += page[j][8] - '0';
                    else
                        PPN += page[j][8] - 'A' + 8;
                    break;
                }
                PPN = -1;
            }
        }


        // 页表没有，则缺页故障
        if(PPN < 0)
        {
            printf(" Can not be determined\n");
            continue;
        }

        CTag = PPN;
        CIndex = (VPO & 0x3c) >> 2;
        COffset = VPO & 0x3;
        // printf("%hx, %hx, %hx\n", CTag, CIndex, COffset);


        int cindex = 0, ctag = 0;
        int flag = 0;
        for(int k = 0; k<len[2]; k++)
        {
            if (cache[k][6] >= '0' && cache[k][6] <= '9')
                cindex = cache[k][6] - '0';
            else
                cindex = cache[k][6] - 'A' + 10;

            if (cache[k][8] >= '0' && cache[k][8] <= '9')
                ctag = (cache[k][8] - '0') * 16;
            else
                ctag = (cache[k][8] - 'A' + 10) * 16;

            if (cache[k][9] >= '0' && cache[k][9] <= '9')
                ctag += cache[k][9] - '0';
            else
                ctag += cache[k][9] - 'A' + 10;

            if(cindex == CIndex && ctag == CTag)
            {
                printf("%c%c\n", cache[k][11+COffset*3], cache[k][12+COffset*3]);
                flag = 1;
            }
            ctag = 0;
        }
        if(flag == 0)
            printf(" Can not be determined\n");
    }
    

    return 0;
}


void getdata(char (*tlb)[128], char (*page)[128], char (*cache)[128], int *len)
{
    char text[LINE_MAX];

    int i=0, j=0, k=0;
    // put the content to tlb[][], page[][], and cache[][]
    while (scanf("%s", text) > 0) 
    {
        if (text[0] == 'T')
            strcpy(tlb[i++], text);
        else if (text[0] == 'P')
            strcpy(page[j++], text);
        else if (text[0] == 'C')
            strcpy(cache[k++], text);
        else
            break;
    }
    len[0] = i;
    len[1] = j;
    len[2] = k;
    // printf("%s\n", tlb[0]);
}



