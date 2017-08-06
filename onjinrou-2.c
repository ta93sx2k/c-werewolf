#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ninzu_nyuryoku(int);

int main (void)
{
    int num, i, j, flag, dice;
    int a[12];
    srand((unsigned)time( NULL ));
    
    printf("プレイ人数を入力してください。(4～10)→");
    scanf("%d", &num);
        
    ninzu_nyuryoku(num);
    
    if(num==4 || num==5 || num==6 || num==7 || num==8 || num==9 || num==10)
    {   
        for(i=0; i<(num+2); i++)
        {
            flag=1;
            while(flag)
            {
                flag=0;
                dice = rand()%(num+2)+1;
                a[i] = dice;
                for(j=0 ; j<i ; j++)
                {
                    if(a[j]==a[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            
            if(a[i]==1 || a[i]==2 || a[i]==7 || a[i]==10 || a[i]==11 || a[i]==12)
                printf("player%d:あなたの役職は村人です。\n", i+1);
            else if (a[i]==3 || a[i]==4 || a[i]==9)
                printf("player%d:あなたの役職は人狼です。\n", i+1);
            else if (a[i]==5)
                printf("player%d:あなたの役職は占い師です。\n", i+1);
            else if (a[i]==6)
                printf("player%d:あなたの役職は怪盗です。\n", i+1);
            else if (a[i]==8)
                printf("player%d:あなたの役職は吊人(てるてる)です。\n", i+1);
        }
    }
    
    return 0;
}

void ninzu_nyuryoku(int num)
{
    if(num==4)
        printf("役職は村人2人、人狼2人、占い師、怪盗の中から%dつです。", num);
    else if(num==5)
        printf("役職は村人3人、人狼2人、占い師、怪盗の中から%dつです。", num);
    else if(num==6)
        printf("役職は村人3人、人狼2人、占い師、怪盗、吊人(てるてる)の中から%dつです。", num);
    else if(num==7)
        printf("役職は村人3人、人狼3人、占い師、怪盗、吊人(てるてる)の中から%dつです。", num);
    else if(num==8)
        printf("役職は村人4人、人狼3人、占い師、怪盗、吊人(てるてる)の中から%dつです。", num);
    else if(num==9)
        printf("役職は村人5人、人狼3人、占い師、怪盗、吊人(てるてる)の中から%dつです。", num);
    else if(num==10)
        printf("役職は村人6人、人狼3人、占い師、怪盗、吊人(てるてる)の中から%dつです。", num);
    else
        printf("エラーが発生しました。対応するプレイ人数を入力してください。(4～10)");
    printf("\n");
}