#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void breakdown(int nop);
void arr(int player_num[8], int pos[8], int rest[2], int count[6], int vote_result[6], int max[6]);
void pos_distribution(int (*player_num), int (*pos), int (*rest), int i, int j, int flag, int nop);
void pos_execution(int (*player_num), int (*pos), int (*rest), int i, int j, int nop, int divine, int swap);
void game(int i, int j, int nop, int vote, int (*player_num), int (*count), int (*vote_result), int (*pos));

int main (void)
{
    int nop, i, j, flag, divine, swap, exchange, vote; //"nop"は"number of people"の略
    int player_num[6]={};
    int pos[6]={};
    int rest[2]={};
    int count[6]={};
    int vote_result[6]={};

    srand((unsigned)time(NULL));

    printf("プレイ人数を入力してください。(4～6)⇒");
    scanf("%d", &nop);
    while(nop!=4 && nop!=5 && nop!=6)
    {
        printf("エラーが発生しました。対応するプレイ人数を入力してください。(4～6)⇒");
        scanf("%d", &nop);
    }
    
    breakdown(nop);

    pos_distribution(player_num, pos, rest, i, j, flag, nop);

    pos_execution(player_num, pos, rest, i, j, nop, divine, swap);

    game(i, j, nop, vote, player_num, count, vote_result, pos);
    
    return 0;
}

void breakdown(int nop)
{
    if(nop==4)
    printf("役職は村人2人、人狼2人、占い師、怪盗の中から%dつです。\n", nop);
    else if(nop==5)
    printf("役職は村人3人、人狼2人、占い師、怪盗の中から%dつです。\n", nop);
    else if(nop==6)
    printf("役職は村人3人、人狼2人、占い師、怪盗、吊人(てるてる)の中から%dつです。\n", nop);
    printf("\n");
}

void arr(int player_num[8], int pos[8], int rest[2], int count[6], int vote_result[6], int max[6]){}

void pos_distribution(int (*player_num), int (*pos), int (*rest), int i, int j, int flag, int nop)
{
    for(i=1; i<=nop; i++)
        {
            player_num[i] = i;
            flag=1;
            while(flag)
            {
                flag=0;
                pos[i]=rand()%(nop+2)+1;
                for(j=1; j<i ; j++)
                {
                    if(pos[j]==pos[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(pos[i]==1 || pos[i]==2 || pos[i]==7)
            printf("player%d:あなたの役職は村人です。\n", player_num[i]);
            else if(pos[i]==3 || pos[i]==4)
            printf("player%d:あなたの役職は人狼です。\n", player_num[i]);
            else if (pos[i]==5)
            printf("player%d:あなたの役職は占い師です。\n", player_num[i]);
            else if (pos[i]==6) 
            printf("player%d:あなたの役職は怪盗です。\n", player_num[i]);
            else if (pos[i]==8)
            printf("player%d:あなたの役職は吊人です。\n", player_num[i]);
        }
    for(i=1; i<=2; i++)
    {
        flag=1;
        while(flag)
        {
            flag=0;
            rest[i]=rand()%(nop+2)+1;
            while(rest[1]==rest[2])
            {
                rest[2]=rand()%(nop+2)+1;
            }
            for(j=1; j<=nop; j++)
            {
                if(rest[i]==pos[j])
                {
                    flag=1;
                    break;
                }
            }
        }
    }   

    printf("\n");
}

void pos_execution(int (*player_num), int (*pos), int (*rest), int i, int j, int nop, int divine, int swap)
{
    for(i=1; i<=nop; i++)
    {
        if(pos[i]==1 || pos[i]==2 || pos[i]==7)
        printf("player%d:村人は議論をして人狼を探してください。\n", player_num[i]);
            
        if(pos[i]==3 || pos[i]==4)
        {
            if(pos[i]==3)
            {
                printf("player%d:人狼は仲間と協力して村人を騙してください。\n", player_num[i]);
                for(j=1; j<=nop; j++)
                {
                    if(pos[j]==4)
                    printf("        仲間はplayer%dです。\n", player_num[j]);
                }
                if(rest[1]==4 || rest[2]==4)
                printf("        仲間はいませんでした。\n");
            }
            if(pos[i]==4)
            {
                printf("player%d:人狼は仲間と協力して村人を騙してください。\n", player_num[i]);
                for(j=1; j<=nop; j++)
                {
                    if(pos[j]==3)
                    printf("        仲間はplayer%dです。\n", player_num[j]);
                }
                if(rest[1]==3 || rest[2]==3)
                printf("        仲間はいませんでした。\n");
            }
        }

        if(pos[i]==5)
        {
            printf("player%d:占い師はプレイヤーの役職、もしくは選ばれていない役職を見ることができます。(0)\n", player_num[i]);
            printf("        占いたいプレイヤーのプレイヤー番号を入力してください。(0～%d)⇒", nop);
            scanf("%d", &divine);
            while(divine==player_num[i] || divine>nop || divine<0)
            {
                printf("        エラーが発生しました。対応するプレイヤー番号を入力してください。(0～%d)⇒", nop);
                scanf("%d", &divine);  
            }
            if(divine==1 || divine==2 || divine==3 || divine==4 || divine==5 || divine==6)
            { 
                if(pos[divine]==1 || pos[divine]==2 || pos[divine]==7)
                printf("        player%dの役職は村人です。\n", player_num[divine]);
                else if(pos[divine]==3 || pos[divine]==4)
                printf("        player%dの役職は人狼です。\n", player_num[divine]);
                else if(pos[divine]==6)
                printf("        player%dの役職は怪盗です。\n", player_num[divine]);
                else if(pos[divine]==8)
                printf("        player%dの役職は吊人です。\n", player_num[divine]);
            }
            if(divine==0)
            {
                for(j=1; j<=2; j++)
                {
                    if(rest[j]==1 || rest[j]==2 || rest[j]==7)
                    printf("        選ばれていない役職は村人です。\n");
                    else if(rest[j]==3 || rest[j]==4)
                    printf("        選ばれていない役職は人狼です。\n");
                    else if(rest[j]==6)
                    printf("        選ばれていない役職は怪盗です。\n");
                    else if(rest[j]==8)
                    printf("        選ばれていない役職は吊人です。\n");
                }
            }      
        }
        
        if(pos[i]==6)
        {
            printf("player%d:怪盗は他プレイヤーと役職を交換することができます。\n", player_num[i]);
            printf("        交換したいプレイヤーのプレイヤー番号を入力してください。\n        役職の交換を行いたくない場合は自分のプレイヤー番号を入力してください。(1～%d)⇒", nop);
            scanf("%d", &swap);
            while(swap>nop || swap<1)
            {
                printf("        エラーが発生しました。対応するプレイヤー番号を入力してください。\n        役職の交換を行いたくない場合は自分のプレイヤー番号を入力してください。(1～%d)⇒", nop);
                scanf("%d", &swap);   
            }
            if(pos[swap]==1 || pos[swap]==2 || pos[swap]==7)
            printf("        交換後のあなたの役職は村人です。\n", player_num[i]);
            else if(pos[swap]==3 || pos[swap]==4)
            printf("        交換後のあなたの役職は人狼です。\n", player_num[i]);
            else if(pos[swap]==5)
            printf("        交換後のあなたの役職は占い師です。\n", player_num[i]);
            else if(pos[swap]==6)
            printf("        役職の交換を行いませんでした。\n", player_num[i]);
            else if(pos[swap]==8)
            printf("        交換後のあなたの役職は吊人です。\n", player_num[i]);
        }
            
        if(pos[i]==8)
        printf("player%d:吊人は人狼チームにも村人チームにも属しません。\n        処刑されたときに勝利します。\n", player_num[i]);
        printf("\n");
    }
        
    for(i=1; i<=nop; i++)
    {
        if(pos[i]==6)
        {
            if(pos[swap]==1 || pos[swap]==2 || pos[swap]==7 )
            {
                pos[i]=pos[swap];
                pos[swap]=6;
            }
            else if(pos[swap]==3 || pos[swap]==4)
            {
                pos[i]=pos[swap];
                pos[swap]=6;
            }
            else if(pos[swap]==5)
            {
                pos[i]=pos[swap];
                pos[swap]=6;
            }
            else if(pos[swap]==8)
            {
                pos[i]=pos[swap];
                pos[swap]=6;
            }
        }
    }
}

void game(int i, int j, int nop, int vote, int (*player_num), int (*count), int (*vote_result), int (*pos))
{
    printf("議論時間が終了しました。これから投票時間に移ります。\n");
        for(i=1; i<=nop; i++)
        {
            printf("player%d:あなたが人狼だと思うプレイヤーのプレイヤー番号を入力してください。(1～%d)→", player_num[i], nop);
            scanf("%d", &vote);
            while(vote==player_num[i])
            {
                printf("        エラーが発生しました。自分以外の対応するプレイヤー番号を入力してください。(1～%d)→", nop);
                scanf("%d", &vote);
            }
            for(j=1; j<=vote; j++)
            {
                if(j==vote)
                {
                    count[vote]=count[vote]+1;
                    printf("player%dはplayer%dに投票しました。\n", player_num[i], player_num[vote]);
                    vote_result[i]=vote;
                    printf("\n");
                }
            }
        }

        if(nop==4)
        {
            if(count[1]>count[2] && count[1]>count[3] && count[1]>count[4])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[1]);
                if(pos[1]!=3 && pos[1]!=4 && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 ||pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[2]>count[1] && count[2]>count[3] && count[2]>count[4])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[2]);
                if(pos[2]!=3 && pos[2]!=4 && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 ||pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[3]>count[1] && count[3]>count[2] && count[3]>count[4])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[3]);
                if(pos[3]!=3 && pos[3]!=4 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 ||pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[4]>count[1] && count[4]>count[2] && count[4]>count[3])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[4]);
                if(pos[4]!=3 && pos[4]!=4 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 ||pos[3]==3 || pos[3]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[1]==count[2] && count[1]>count[3] && count[1]>count[4])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[2]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[2]!=3 && pos[2]!=4) && (pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[3] && count[1]>count[2] && count[1]>count[4])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[3]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[3]!=3 && pos[3]!=4) && (pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            } 
            if(count[1]==count[4] && count[1]>count[2] && count[1]>count[3])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[4]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[3] && count[2]>count[1] && count[2]>count[4])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[3]);
                if((pos[2]!=3 && pos[2]!=4) && (pos[3]!=3 && pos[3]!=4) && (pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[4] && count[2]>count[1] && count[2]>count[3])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[4]);
                if((pos[2]!=3 && pos[2]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[3]==count[4] && count[3]>count[1] && count[3]>count[2])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[3], player_num[4]);
                if((pos[3]!=3 && pos[3]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
        }
        if(nop==5)
        {
            if(count[1]>count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[1]);
                if(pos[1]!=3 && pos[1]!=4 && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 ||pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[2]>count[1] && count[2]>count[3] && count[2]>count[4] && count[2]>count[5])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[2]);
                if(pos[2]!=3 && pos[2]!=4 && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 ||pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[3]>count[1] && count[3]>count[2] && count[3]>count[4] && count[3]>count[5])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[3]);
                if(pos[3]!=3 && pos[3]!=4 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 ||pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[4]>count[1] && count[4]>count[2] && count[4]>count[3] && count[4]>count[5])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[4]);
                if(pos[4]!=3 && pos[4]!=4 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 ||pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[5]>count[1] && count[5]>count[2] && count[5]>count[3] && count[5]>count[4])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[5]);
                if(pos[5]!=3 && pos[5]!=4 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 ||pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");    
            }
            if(count[1]==count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[2]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[2]!=3 && pos[2]!=4) && (pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[3] && count[1]>count[2] && count[1]>count[4] && count[1]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[3]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[3]!=3 && pos[3]!=4) && (pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            } 
            if(count[1]==count[4] && count[1]>count[2] && count[1]>count[3] && count[1]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[4]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[5] && count[1]>count[2] && count[1]>count[3] && count[1]>count[4])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[5]);
                if((pos[1]!=3 && pos[1]!=4) && (pos[5]!=3 && pos[5]!=4) && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[3] && count[2]>count[1] && count[2]>count[4] && count[2]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[3]);
                if((pos[2]!=3 && pos[2]!=4) && (pos[3]!=3 && pos[3]!=4) && (pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[4] && count[2]>count[1] && count[2]>count[3] && count[2]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[4]);
                if((pos[2]!=3 && pos[2]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[5] && count[2]>count[1] && count[2]>count[3] && count[2]>count[4])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[5]);
                if((pos[2]!=3 && pos[2]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[3]==count[4] && count[3]>count[1] && count[3]>count[2] && count[3]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[3], player_num[4]);
                if((pos[3]!=3 && pos[3]!=4) && (pos[4]!=3 && pos[4]!=4) && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[3]==count[5] && count[3]>count[1] && count[3]>count[2] && count[3]>count[4])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[3], player_num[5]);
                if((pos[3]!=3 && pos[3]!=4) && (pos[5]!=3 && pos[5]!=4) && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
            if(count[4]==count[5] && count[4]>count[1] && count[4]>count[2] && count[4]>count[3])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[4], player_num[5]);
                if((pos[4]!=3 && pos[4]!=4) && (pos[5]!=3 && pos[5]!=4) && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else 
                printf("勝利チームは存在しません。\n");
            }
        }
        if(nop==6)
        {
            if(count[1]>count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5] && count[1]>count[6])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[1]);
                if(pos[1]!=3 && pos[1]!=4 && pos[1]!=8 && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[1]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]>count[1] && count[2]>count[3] && count[2]>count[4] && count[2]>count[5] && count[2]>count[6])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[2]);
                if(pos[2]!=3 && pos[2]!=4 && pos[2]!=8 && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[2]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[3]>count[1] && count[3]>count[2] && count[3]>count[4] && count[3]>count[5] && count[3]>count[6])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[3]);
                if(pos[3]!=3 && pos[3]!=4 && pos[3]!=8 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[3]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[4]>count[1] && count[4]>count[2] && count[4]>count[3] && count[4]>count[5] && count[4]>count[6])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[4]);
                if(pos[4]!=3 && pos[4]!=4 && pos[4]!=8 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[4]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[5]>count[1] && count[5]>count[2] && count[5]>count[3] && count[5]>count[4] && count[5]>count[6])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[5]);
                if(pos[5]!=3 && pos[5]!=4 && pos[5]!=8 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[5]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[6]>count[1] && count[6]>count[2] && count[6]>count[3] && count[6]>count[4] && count[6]>count[5])
            {
                printf("投票の結果、player%dを処刑しました。\n", player_num[6]);
                if(pos[6]!=3 && pos[6]!=4 && pos[6]!=8 && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[6]==3 || pos[6]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[6]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5] && count[1]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[2]);
                if((pos[1]!=3 && pos[1]!=4 && pos[1]!=8 && pos[2]!=3 && pos[2]!=4 && pos[2]!=8) && (pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[1]==8 || pos[2]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[3] && count[1]>count[2] && count[1]>count[4] && count[1]>count[5] && count[1]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[3]);
                if((pos[1]!=3 && pos[1]!=4 && pos[1]!=8 && pos[3]!=3 && pos[3]!=4 pos[3]!=8) && (pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[1]==8 || pos[3]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[4] && count[1]>count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[4]);
                if((pos[1]!=3 && pos[1]!=4 && pos[1]!=8 pos[4]!=3 && pos[4]!=4 && pos[4]!=8) && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[1]==8 || pos[4]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[5] && count[1]>count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[5]);
                if((pos[1]!=3 && pos[1]!=4  && pos[1]!=8 && pos[5]!=3 && pos[5]!=4 && pos[5]!=8) && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[1]==8 || pos[5]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[1]==count[6] && count[1]>count[2] && count[1]>count[3] && count[1]>count[4] && count[1]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[1], player_num[6]);
                if((pos[1]!=3 && pos[1]!=4  && pos[1]!=8  && pos[6]!=3 && pos[6]!=4 && pos[6]!=4) && (pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[1]==3 || pos[1]==4 || pos[6]==3 || pos[6]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[1]==8 || pos[6]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[3] && count[2]>count[1] && count[2]>count[4] && count[2]>count[5] && count[2]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[3]);
                if((pos[2]!=3 && pos[2]!=4 && pos[2]!=8 pos[3]!=3 && pos[3]!=4 && pos[3]!=8) && (pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[3]==3 || pos[3]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[2]==8 || pos[3]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[4] && count[2]>count[1] && count[2]>count[3] && count[2]>count[5] && count[2]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[4]);
                if((pos[2]!=3 && pos[2]!=4 && pos[2]!=8 pos[4]!=3 && pos[4]!=4 && pos[4]!=8) && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[2]==8 || pos[4]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[5] && count[2]>count[1] && count[2]>count[3] && count[2]>count[4] && count[2]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[5]);
                if((pos[2]!=3 && pos[2]!=4 && pos[2]!=8 pos[3]!=3 && pos[5]!=4 && pos[5]!=8) && (pos[1]==3 || pos[1]==4 || pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[2]==8 || pos[5]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[2]==count[6] && count[2]>count[1] && count[2]>count[3] && count[2]>count[4] && count[2]>count[5])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[2], player_num[6]);
                if((pos[2]!=3 && pos[2]!=4 && pos[2]!=8 pos[6]!=3 && pos[6]!=4 && pos[6]!=8) && (pos[1]==3 || pos[1]==4 || pos[4]==3 || pos[4]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[2]==3 || pos[2]==4 || pos[6]==3 || pos[6]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[2]==8 || pos[6]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[3]==count[4] && count[3]>count[1] && count[3]>count[2] && count[3]>count[5] && count[3]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[3], player_num[4]);
                if((pos[3]!=3 && pos[3]!=4 && pos[3]!=8 pos[4]!=3 && pos[4]!=4 && pos[4]!=8) && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[5]==3 || pos[5]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4 || pos[4]==3 || pos[4]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[3]==8 || pos[4]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            if(count[3]==count[5] && count[3]>count[1] && count[3]>count[2] && count[3]>count[4] && count[3]>count[6])
            {
                printf("投票の結果、player%dとplayer%dを処刑しました。\n", player_num[3], player_num[5]);
                if((pos[3]!=3 && pos[3]!=4 && pos[3]!=8 pos[5]!=3 && pos[5]!=4 && pos[5]!=8) && (pos[1]==3 || pos[1]==4 || pos[2]==3 || pos[2]==4 || pos[4]==3 || pos[4]==4 || pos[6]==3 || pos[6]==4))
                printf("人狼チームの勝利です。\n");
                else if(pos[3]==3 || pos[3]==4 || pos[5]==3 || pos[5]==4)
                printf("村人チームの勝利です。\n");
                else if(pos[3]==8 || pos[5]==8)
                printf("吊人の勝利です。\n");
                else
                printf("勝利チームは存在しません。\n");
            }
            
        }

        for(i=1; i<=nop; i++)
        {
            if(pos[i]==1 || pos[i]==2 || pos[i]==7)
            {
                printf("%d票　player%d(村人)　　→　player%d\n", count[i], player_num[i], vote_result[i]);
            }
            else if(pos[i]==3 || pos[i]==4)
            {
                printf("%d票　player%d(人狼)　　→　player%d\n", count[i], player_num[i], vote_result[i]);
            }
            else if(pos[i]==5)
            {
                printf("%d票　player%d(占い師)　→　player%d\n", count[i], player_num[i], vote_result[i]);
            }
            else if(pos[i]==6)
            {
                printf("%d票　player%d(怪盗)　　→　player%d\n", count[i], player_num[i], vote_result[i]);
            }
            else if(pos[i]==8)
            {
                printf("%d票　player%d(吊人)　　→　player%d\n", count[i], player_num[i], vote_result[i]);
            }
        }           
}