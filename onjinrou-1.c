#include <stdio.h>

void ninzu_nyuryoku(int);

int main (void)
{
    int num, i, j;
    char name[10][50];
    
    printf("プレイ人数を入力してください。(4～10)→");
    scanf("%d", &num);
        
    ninzu_nyuryoku(num);
    
    if(num==4 || num==5 || num==6 || num==7 || num==8 || num==9 || num==10)
    {
        printf("名前を入力してください。\n");
        
        for(i=0; i<num; i++)
        {
            for(j=0; j=50; j++)
            {
                scanf("%s",&name[i][j]);
                if (name[i][j] = "\0")break;
            }
        }
        
        for(i=0; i<num; i++)
        {
            printf("プレイヤー%d:" ,i+1);
            for(j=0; name[i][j]!="\0"; j++)
            {
                printf("%s", i+1, name[i][j]);
            }
            printf("\n");
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