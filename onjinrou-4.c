#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ninzu_nyuryoku(int);

int main (void)
{
    int num, i, j, k, flag, dice, uranai, kaitou, touhyou; 
    int yakusyoku[12];
    int player_number[12];
    int touhyou_result[10]={0,0,0,0,0,0,0,0,0,0};
    int count[10]={0,0,0,0,0,0,0,0,0,0};
    int max[10]={0,0,0,0,0,0,0,0,0,0};
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
            
            if(yakusyoku[num+1]==1 || yakusyoku[num+1]==2 || yakusyoku[num+1]==7 || yakusyoku[num+1]==10 || yakusyoku[num+1]==11 || yakusyoku[num+1]==12 || yakusyoku[num+2]==1 || yakusyoku[num+2]==2 || yakusyoku[num+2]==7 || yakusyoku[num+2]==10 || yakusyoku[num+2]==11 || yakusyoku[num+2]==12)
                printf("");
            else if(yakusyoku[i]==1 || yakusyoku[i]==2 || yakusyoku[i]==7 || yakusyoku[i]==10 || yakusyoku[i]==11 || yakusyoku[i]==12)
                printf("player%2d:あなたの役職は村人です。\n", player_number[i]);          
            else if(yakusyoku[num+1]==3 || yakusyoku[num+1]==4 || yakusyoku[num+1]==9 || yakusyoku[num+2]==3 || yakusyoku[num+2]==4 || yakusyoku[num+2]==9)
                printf("");
            else if(yakusyoku[i]==3 || yakusyoku[i]==4 || yakusyoku[i]==9)
                printf("player%2d:あなたの役職は人狼です。\n", player_number[i]);
            else if(yakusyoku[num+1]==5 || yakusyoku[num+2]==5)
                printf("");
            else if (yakusyoku[i]==5)
                printf("player%2d:あなたの役職は占い師です。\n", player_number[i]);
            else if(yakusyoku[num+1]==6 || yakusyoku[num+2]==6)
                printf("");
            else if (yakusyoku[i]==6)
                printf("player%2d:あなたの役職は怪盗です。\n", player_number[i]);
            else if(yakusyoku[num+1]==8 || yakusyoku[num+2]==8)
                printf("");
            else if (yakusyoku[i]==8)
                printf("player%2d:あなたの役職は吊人です。\n", player_number[i]);           
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
                    for(k=1; k<=num; k++)
                    {
                        if(yakusyoku[k]==9)
                            printf("         仲間はplayer%2dです。\n", player_number[k]);
                    }
                    if((yakusyoku[num+1]==4 || yakusyoku[num+2]==4) && (yakusyoku[num+1]==9 || yakusyoku[num+2]==9))
                        printf("         仲間はいませんでした。\n");
                    else if(yakusyoku[k]!=9 && yakusyoku[num+1]==4 || yakusyoku[num+2]==4)
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
                    for(k=1; k<=num; k++)
                    {
                        if(yakusyoku[k]==9)
                            printf("         仲間はplayer%2dです。\n", player_number[k]);
                    }
                    if((yakusyoku[num+1]==3 || yakusyoku[num+2]==3) && (yakusyoku[num+1]==9 || yakusyoku[num+2]==9))
                        printf("         仲間はいませんでした。\n");
                    else if(yakusyoku[k]!=9 && yakusyoku[num+1]==3 || yakusyoku[num+2]==3)
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
                    for(k=1; k<=num; k++)
                    {
                        if(yakusyoku[k]==4)
                            printf("         仲間はplayer%2dです。\n", player_number[k]);
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
                        printf("         player%2dの役職は吊人です。\n", player_number[uranai]);
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
                        printf("         選ばれていない役職は吊人です。\n");
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
                        printf("         選ばれていない役職は吊人です。\n");
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
                    printf("         交換後のあなたの吊人です。\n", player_number[i]);
            }
            
            if(yakusyoku[i]==8)
                printf("player%2d:吊人は人狼チームにも村人チームにも属しません。\n         処刑されたときに勝利します。\n", player_number[i]);
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
        
        printf("議論時間が終了しました。これから投票時間に移ります。\n");
        for(i=1; i<=num; i++)
        {
            printf("player%2d:あなたが人狼だと思うプレイヤーのプレイヤー番号を入力してください。(1～%d)→", player_number[i], num);
            scanf("%d", &touhyou);
            while(touhyou==i)
            {
                printf("         エラーが発生しました。自分以外の対応するプレイヤー番号を入力してください。(1～%d)→", num);
                scanf("%d", &touhyou);
            }
            for(j=1; j<=num; j++)
            {
                if(j==touhyou)
                {
                    count[touhyou]=count[touhyou]+1;
                    printf("player%2dはplayer%2dに投票しました。\n", player_number[i], player_number[touhyou]);
                    touhyou_result[i]=touhyou;
                    printf("\n");
                }
            }
        }
        for(i=1; i<=num; i++)
        {
            for(j=1; j<=i; j++)
            {
                if(count[i]>count[j] && i!=j)
                {
                    max[i]=max[i]+1;
                }
                else if(count[i]<count[j] && i!=j)
                {
                    max[j]=max[j]+1;
                }
                else if(count[i]==count[j] &&i!=j)
                {
                    max[i]=max[i]+1;
                    max[j]=max[j]+1;
                }
            }
        }
        if(num==4)
        {
            if(max[1]==max[2]==max[3]==max[4])
            {
                printf("投票の結果、誰も処刑しないことにしました。\n");
                if((yakusyoku[1]!=3 || yakusyoku[1]!=4) && (yakusyoku[2]!=3 || yakusyoku[2]!=4) && (yakusyoku[3]!=3 || yakusyoku[3]!=4) && (yakusyoku[4]!=3 || yakusyoku[4]!=4))
                    printf("村人チームの勝利です。\n");
                else
                    printf("人狼チームの勝利です。\n");
            }
            if(max[1]>max[2] && max[1]>max[3] && max[1]>max[4])
            {
                printf("投票の結果、player%2dを処刑することにしました。\n", player_number[1]);
                if((yakusyoku[1]!=3 && yakusyoku[1]!=4) && (yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[3]==3 || yakusyoku[3]==4 || yakusyoku[4]==3 || yakusyoku[4]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[1]==3 || yakusyoku[1]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[2]>max[1] && max[2]>max[3] && max[2]>max[4])
            {
                printf("投票の結果、player%2dを処刑することにしました。\n", player_number[2]);
                if((yakusyoku[2]!=3 && yakusyoku[2]!=4) && (yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[3]==3 || yakusyoku[3]==4 || yakusyoku[4]==3 || yakusyoku[4]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[2]==3 || yakusyoku[2]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[3]>max[1] && max[3]>max[2] && max[3]>max[4])
            {
                printf("投票の結果、player%2dを処刑することにしました。\n", player_number[3]);
                if((yakusyoku[3]!=3 && yakusyoku[3]!=4) && (yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[4]==3 || yakusyoku[4]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[3]==3 || yakusyoku[3]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[4]>max[1] && max[4]>max[2] && max[4]>max[3])
            {
                printf("投票の結果、player%2dを処刑することにしました。\n", player_number[4]);
                if((yakusyoku[4]!=3 && yakusyoku[4]!=4) && (yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[3]==3 || yakusyoku[3]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[4]==3 || yakusyoku[4]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[1]==max[2] && max[1]>max[3] && max[1]>max[4])
            {
                printf("投票の結果、player%2dとplater%2dを処刑することにしました。\n", player_number[1], player_number[2]);
                if((yakusyoku[1]!=3 && yakusyoku[1]!=4) && (yakusyoku[2]!=3 && yakusyoku[2]!=4) && (yakusyoku[3]==3 || yakusyoku[3]==4 || yakusyoku[4]==3 || yakusyoku[4]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[2]==3 || yakusyoku[2]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[1]==max[3] && max[1]>max[2] && max[1]>max[4])
            {
                printf("投票の結果、player%2dとplater%2dを処刑することにしました。\n", player_number[1], player_number[3]);
                if((yakusyoku[1]!=3 && yakusyoku[1]!=4) && (yakusyoku[3]!=3 && yakusyoku[3]!=4) && (yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[4]==3 || yakusyoku[4]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[3]==3 || yakusyoku[3]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[1]==max[4] && max[1]>max[2] && max[1]>max[3])
            {
                printf("投票の結果、player%2dとplater%2dを処刑することにしました。\n", player_number[1], player_number[4]);
                if((yakusyoku[1]!=3 && yakusyoku[1]!=4) && (yakusyoku[4]!=3 && yakusyoku[4]!=4) && (yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[3]==3 || yakusyoku[3]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[4]==3 || yakusyoku[4]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[2]==max[3] && max[2]>max[1] && max[2]>max[4])
            {
                printf("投票の結果、player%2dとplater%2dを処刑することにしました。\n", player_number[2], player_number[3]);
                if((yakusyoku[2]!=3 && yakusyoku[2]!=4) && (yakusyoku[3]!=3 && yakusyoku[3]!=4) && (yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[4]==3 || yakusyoku[4]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[3]==3 || yakusyoku[3]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[2]==max[4] && max[2]>max[1] && max[2]>max[3])
            {
                printf("投票の結果、player%2dとplater%2dを処刑することにしました。\n", player_number[2], player_number[4]);
                if((yakusyoku[2]!=3 && yakusyoku[2]!=4) && (yakusyoku[4]!=3 && yakusyoku[4]!=4) && (yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[3]==3 || yakusyoku[3]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[2]==3 || yakusyoku[2]==4 || yakusyoku[4]==3 || yakusyoku[4]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
            if(max[3]==max[4] && max[3]>max[1] && max[3]>max[2])
            {
                printf("投票の結果、player%2dとplater%2dを処刑することにしました。\n", player_number[3], player_number[4]);
                if((yakusyoku[3]!=3 && yakusyoku[3]!=4) && (yakusyoku[4]!=3 && yakusyoku[4]!=4) && (yakusyoku[1]==3 || yakusyoku[1]==4 || yakusyoku[2]==3 || yakusyoku[2]==4))
                    printf("人狼チームの勝利です。\n");
                else if(yakusyoku[3]==3 || yakusyoku[3]==4 || yakusyoku[4]==3 || yakusyoku[4]==4)
                    printf("村人チームの勝利です。\n");
                else 
                    printf("勝利チームは存在しません。\n");
            }
        }
        printf("\n");
        for(i=1; i<=num; i++)
        {
            if(yakusyoku[i]==1 || yakusyoku[i]==2 || yakusyoku[i]==7 || yakusyoku[i]==10 || yakusyoku[i]==11 || yakusyoku[i]==12)
            {
                printf("%d票　player%2d(村人) →　player%2d\n", count[i], i, touhyou_result[i]);
            }
            else if(yakusyoku[i]==3 || yakusyoku[i]==4 || yakusyoku[i]==9)
            {
                printf("%d票　player%2d(人狼) →　player%2d\n", count[i], i, touhyou_result[i]);
            }
            else if(yakusyoku[i]==5)
            {
                printf("%d票　player%2d(占い師) →　player%2d\n", count[i], i, touhyou_result[i]);
            }
            else if(yakusyoku[i]==6)
            {
                printf("%d票　player%2d(怪盗) →　player%2d\n", count[i], i, touhyou_result[i]);
            }
            else if(yakusyoku[i]==8)
            {
                printf("%d票　player%2d(吊人) →　player%2d\n", count[i], i, touhyou_result[i]);
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