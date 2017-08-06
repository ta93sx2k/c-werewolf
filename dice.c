#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    int num, i, j, flag, dice;
    int a[12];
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
            printf("%d", a[i]);
        }
     }
return 0;    
}