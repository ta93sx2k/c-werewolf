#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    int num, i, j, flag, dice;
    int dice_number[12];
    int player_number[12];
    srand((unsigned)time( NULL ));
    
    printf("プレイ人数を入力してください。(4～10)→");
    scanf("%d", &num);
    
     if(num==4 || num==5 || num==6 || num==7 || num==8 || num==9 || num==10)
     {   
        for(i=0; i<(num+2); i++)
        {
            flag=1;
            while(flag)
            {
                player_number[i] = i+1;
                flag=0;
                dice = rand()%(num+2)+1;
                dice_number[i] = dice;
                for(j=0 ; j<i ; j++)
                {
                    if(dice_number[j]==dice_number[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            printf("player_number%2d → dice_number%2d\n", player_number[i], dice_number[i]);
        }
     }
return 0;    
}