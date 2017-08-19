#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int yakusyoku_haibun(int, int, int, int, int, int, int);

int main(void)
{
    int i, j, num, flag, dice;
    int yakusyoku[12];
    int player_number[12];
    srand((unsigned)time( NULL ));
    
    yakusyoku_haibun(i, j, num, flag, dice, player_number[12], yakusyoku[12]);
    
    return 0;
}

int yakusyoku_haibun(int i, int j, int num, int flag, int dice, int player_number[12], int yakusyoku[12])
{
    for(i=0; i<(num+2); i++)
        {
            player_number[i] = i+1;
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
                return yakusyoku[i];
                printf("player%2d →　%2d", player_number[i], yakusyoku[i]);
            }
         }
}