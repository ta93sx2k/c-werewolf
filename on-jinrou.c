#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void breakdown(int);
int main (void)
{
    int num,  i, j, flag;
    int player_num[8];
    int pos[8];
    srand((unsigned)time(NULL));

    printf("プレイ人数を入力してください。(4～6)⇒");
    scanf("%d", &num);
    while(num!=4 && num!=5 && num!=6)
    {
        printf("エラーが発生しました。対応するプレイ人数を入力してください。(4～6)⇒");
        scanf("%d", &num);
    }
    
    breakdown(num);
    printf("\n");

    if(num==4 || num==5 || num==6)
    {
        for(i=1; i<=(num+2); i++)
        {
            player_num[i] = i;
            flag = 1;
            while(flag)
            {
                flag = 0;
                pos[i] = rand()%(num+2)+1;
                for(j=1 ; j<i ; j++)
                {
                    if(pos[j]==pos[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(pos[num+1]==1 || pos[num+2]==1 || pos[num+1]==2 || pos[num+2]==2 || pos[num+1]==7 || pos[num+2]==7)
            printf("");
            else if(pos[i]==1 || pos[i]==2 || pos[i]==7)
            printf("player%d:あなたの役職は村人です。\n", player_num[i]);
            else if(pos[num+1]==3 || pos[num+2]==3 || pos[num+1]==4 || pos[num+2]==4)
            printf("");          
            else if(pos[i]==3 || pos[i]==4)
            printf("player%d:あなたの役職は人狼です。\n", player_num[i]);
            else if(pos[num+1]==5 || pos[num+2]==5)
            printf("");
            else if (pos[i]==5)
            printf("player%d:あなたの役職は占い師です。\n", player_num[i]);
            else if(pos[num+1]==6 || pos[num+2]==6)
            printf("");
            else if (pos[i]==6) 
            printf("player%d:あなたの役職は怪盗です。\n", player_num[i]);
            else if(pos[num+1]==8 || pos[num+2]==8)
            printf("");
            else if (pos[i]==8)
            printf("player%d:あなたの役職は吊人です。\n", player_num[i]);
        }           
        printf("\n");
    }

    return 0;
}

void breakdown(int num)
{
    if(num==4)
    printf("役職は村人2人、人狼2人、占い師、怪盗の中から%dつです。\n", num);
    else if(num==5)
    printf("役職は村人3人、人狼2人、占い師、怪盗の中から%dつです。\n", num);
    else if(num==6)
    printf("役職は村人3人、人狼2人、占い師、怪盗、吊人(てるてる)の中から%dつです。\n", num);
}