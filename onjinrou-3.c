#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ninzu_nyuryoku(int);

int main (void)
{
    int num, i, j, flag, dice, uranai, kaitou;
    int yakusyoku[12];
    int player_number[12];
    srand((unsigned)time( NULL ));
    
    printf("プレイ人数を入力してください。(4～10)→");
    scanf("%d", &num);
        
    ninzu_nyuryoku(num);
    printf("\n");
    
    if(num==4 || num==5 || num==6 || num==7 || num==8 || num==9 || num==10)
    {   
        for(i=1; i<=(num+2); i++)
        {
            player_number[i] = i;
            flag = 1;
            while(flag)
            {
                flag = 0;
                dice = rand()%(num+2)+1;
                yakusyoku[i] = dice;
                for(j=0 ; j<i ; j++)
                {
                    if(yakusyoku[j]==yakusyoku[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            
            if(yakusyoku[i]==1 || yakusyoku[i]==2 || yakusyoku[i]==7 || yakusyoku[i]==10 || yakusyoku[i]==11 || yakusyoku[i]==12)
                printf("player%2d:あなたの役職は村人です。\n", player_number[i]);
            else if(yakusyoku[i]==3 || yakusyoku[i]==4 || yakusyoku[i]==9)
                printf("player%2d:あなたの役職は人狼です。\n", player_number[i]);
            else if (yakusyoku[i]==5)
                printf("player%2d:あなたの役職は占い師です。\n", player_number[i]);
            else if (yakusyoku[i]==6)
                printf("player%2d:あなたの役職は怪盗です。\n", player_number[i]);
            else if (yakusyoku[i]==8)
                printf("player%2d:あなたの役職は吊人(てるてる)です。\n", player_number[i]);
                
        }
        printf("\n");
        
        for(i=1; i<=num; i++)
        {
            if(yakusyoku[i]==1 || yakusyoku[i]==2 || yakusyoku[i]==7 || yakusyoku[i]==10 || yakusyoku[i]==11 || yakusyoku[i]==12)
                printf("player%2d:村人は議論をして人狼を探してください。\n", player_number[i]);
            
            if(yakusyoku[i]==3 || yakusyoku[i]==4 || yakusyoku[i]==9)
            {
                if(yakusyoku[i]==3)
                {
                    printf("player%2d:人狼は仲間と協力して村人を騙してください。\n", player_number[i]);
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==4)
                            printf("         仲間はplayer%2dです。\n", player_number[j]);
                    }
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==9)
                            printf("         仲間はplayer%2dです。\n", player_number[j]);
                    }
                    if((yakusyoku[num+1]==4 || yakusyoku[num+2]==4) && (yakusyoku[num+1]==9 || yakusyoku[num+2]==9))
                        printf("         仲間はいませんでした。\n");
                }
                if(yakusyoku[i]==4)
                {
                    printf("player%2d:人狼は仲間と協力して村人を騙してください。\n", player_number[i]);
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==3)
                            printf("         仲間はplayer%2dです。\n", player_number[j]);
                    }
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==9)
                            printf("         仲間はplayer%2dです。\n", player_number[j]);
                    }
                    if((yakusyoku[num+1]==3 || yakusyoku[num+2]==3) && (yakusyoku[num+1]==9 || yakusyoku[num+2]==9))
                        printf("         仲間はいませんでした。\n");
                }
                if(yakusyoku[i]==9)
                {
                    printf("player%2d:人狼は仲間と協力して村人を騙してください。\n", player_number[i]);
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==3)
                            printf("         仲間はplayer%2dです。\n", player_number[j]);
                    }
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==4)
                            printf("         仲間はplayer%2dです。\n", player_number[j]);
                    }
                    if((yakusyoku[num+1]==3 || yakusyoku[num+2]==3) && (yakusyoku[num+1]==4 || yakusyoku[num+2]==4))
                        printf("         仲間はいませんでした。\n");
                }
            }
        
            if(yakusyoku[i]==5)
            {
                printf("player%2d:占い師はプレイヤーの役職、もしくは選ばれていない役職を見ることができます。(0)\n", player_number[i]);
                printf("         占いたいプレイヤーのプレイヤー番号を入力してください。(0～%d)→", num);
                scanf("%d", &uranai);
                if(uranai==num || uranai==num-1 || uranai==num-2 || uranai==num-3 || uranai==num-4 || uranai==num-5 || uranai==num-6 || uranai==num-7 || uranai==num-8 || uranai==num-9 && uranai!=5)
                { 
                    if(yakusyoku[uranai]==1 || yakusyoku[uranai]==2 || yakusyoku[uranai]==7 || yakusyoku[uranai]==11 || yakusyoku[uranai]==12)
                        printf("         player%2dの役職は村人です。\n", player_number[uranai]);
                    else if(yakusyoku[uranai]==3 || yakusyoku[uranai]==4 || yakusyoku[uranai]==9)
                        printf("         player%2dの役職は人狼です。\n", player_number[uranai]);
                    else if(yakusyoku[uranai]==6)
                        printf("         player%2dの役職は怪盗です。\n", player_number[uranai]);
                    else if(yakusyoku[uranai]==8)
                        printf("         player%2dの役職は吊人(てるてる)です。\n", player_number[uranai]);
                }
                if(uranai==0 && uranai!=5)
                {
                    if(yakusyoku[num+1]==1 || yakusyoku[num+1]==2 || yakusyoku[num+1]==7 || yakusyoku[num+1]==11 || yakusyoku[num+1]==12)
                        printf("         選ばれていない役職は村人です。\n");
                    else if(yakusyoku[num+1]==3 || yakusyoku[num+1]==4 || yakusyoku[num+1]==9)
                        printf("         選ばれていない役職は人狼です。\n");
                    else if(yakusyoku[num+1]==6)
                        printf("         選ばれていない役職は怪盗です。\n");
                    else if(yakusyoku[num+1]==8)
                        printf("         選ばれていない役職は吊人(てるてる)です。\n");
                }
                if(uranai==0 && uranai!=5)
                {
                    if(yakusyoku[num+2]==1 || yakusyoku[num+2]==2 || yakusyoku[num+2]==7 || yakusyoku[num+2]==11 || yakusyoku[num+2]==12)
                        printf("         選ばれていない役職は村人です。\n");
                    else if(yakusyoku[num+2]==3 || yakusyoku[num+2]==4 || yakusyoku[num+2]==9)
                        printf("         選ばれていない役職は人狼です。\n");
                    else if(yakusyoku[num+2]==6)
                        printf("         選ばれていない役職は怪盗です。\n");
                    else if(yakusyoku[num+2]==8)
                        printf("         選ばれていない役職は吊人(てるてる)です。\n");
                }
            }
        
            if(yakusyoku[i]==6)
            {
                printf("player%2d:怪盗は他プレイヤーと役職を交換することができます。\n", player_number[i]);
                printf("         交換したいプレイヤーのプレイヤー番号を入力してください。\n         役職の交換を行いたくないときは自分のプレイヤー番号を入力してください。(1～%d)→", num);
                scanf("%d", &kaitou);
                if(yakusyoku[kaitou]==1 || yakusyoku[kaitou]==2 || yakusyoku[kaitou]==7 || yakusyoku[kaitou]==11 || yakusyoku[kaitou]==12)
                    printf("         交換後のあなたの役職は村人です。\n", player_number[i]);
                else if(yakusyoku[kaitou]==3 || yakusyoku[kaitou]==4 || yakusyoku[kaitou]==9)
                    printf("         交換後のあなたの役職は人狼です。\n", player_number[i]);
                else if(yakusyoku[kaitou]==5)
                    printf("         交換後のあなたの役職は占い師です。\n", player_number[i]);
                else if(yakusyoku[kaitou]==6)
                    printf("         役職の交換を行いませんでした。\n", player_number[i]);
                else if(yakusyoku[kaitou]==8)
                    printf("         交換後のあなたの吊人(てるてる)です。\n", player_number[i]);
            }
            
            if(yakusyoku[i]==8)
                printf("player%2d:吊人(てるてる)は人狼チームにも村人チームにも属しません。\n         処刑されたときに勝利します。\n", player_number[i]);
            printf("\n");
        }
        
        for(i=1; i<=num; i++)
        {
            if(yakusyoku[i]==6)
            {
                if(yakusyoku[kaitou]==1 || yakusyoku[kaitou]==2 || yakusyoku[kaitou]==7 || yakusyoku[kaitou]==11 || yakusyoku[kaitou]==12)
                {
                    yakusyoku[i]=yakusyoku[kaitou];
                    yakusyoku[kaitou]=6;
                }
                else if(yakusyoku[kaitou]==3 || yakusyoku[kaitou]==4 || yakusyoku[kaitou]==9)
                {
                    yakusyoku[i]=yakusyoku[kaitou];
                    yakusyoku[kaitou]=6;
                }
                else if(yakusyoku[kaitou]==5)
                {
                    yakusyoku[i]=yakusyoku[kaitou];
                    yakusyoku[kaitou]=6;
                }
                else if(yakusyoku[kaitou]==8)
                {
                    yakusyoku[i]=yakusyoku[kaitou];
                    yakusyoku[kaitou]=6;
                }
            }
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