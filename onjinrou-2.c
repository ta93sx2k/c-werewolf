#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ninzu_nyuryoku(int);

int main (void)
{
    int num, i, j, flag, dice;
    int a[12];
    srand((unsigned)time( NULL ));
    
    printf("�v���C�l������͂��Ă��������B(4�`10)��");
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
                printf("player%d:���Ȃ��̖�E�͑��l�ł��B\n", i+1);
            else if (a[i]==3 || a[i]==4 || a[i]==9)
                printf("player%d:���Ȃ��̖�E�͐l�T�ł��B\n", i+1);
            else if (a[i]==5)
                printf("player%d:���Ȃ��̖�E�͐肢�t�ł��B\n", i+1);
            else if (a[i]==6)
                printf("player%d:���Ȃ��̖�E�͉����ł��B\n", i+1);
            else if (a[i]==8)
                printf("player%d:���Ȃ��̖�E�͒ݐl(�Ă�Ă�)�ł��B\n", i+1);
        }
    }
    
    return 0;
}

void ninzu_nyuryoku(int num)
{
    if(num==4)
        printf("��E�͑��l2�l�A�l�T2�l�A�肢�t�A�����̒�����%d�ł��B", num);
    else if(num==5)
        printf("��E�͑��l3�l�A�l�T2�l�A�肢�t�A�����̒�����%d�ł��B", num);
    else if(num==6)
        printf("��E�͑��l3�l�A�l�T2�l�A�肢�t�A�����A�ݐl(�Ă�Ă�)�̒�����%d�ł��B", num);
    else if(num==7)
        printf("��E�͑��l3�l�A�l�T3�l�A�肢�t�A�����A�ݐl(�Ă�Ă�)�̒�����%d�ł��B", num);
    else if(num==8)
        printf("��E�͑��l4�l�A�l�T3�l�A�肢�t�A�����A�ݐl(�Ă�Ă�)�̒�����%d�ł��B", num);
    else if(num==9)
        printf("��E�͑��l5�l�A�l�T3�l�A�肢�t�A�����A�ݐl(�Ă�Ă�)�̒�����%d�ł��B", num);
    else if(num==10)
        printf("��E�͑��l6�l�A�l�T3�l�A�肢�t�A�����A�ݐl(�Ă�Ă�)�̒�����%d�ł��B", num);
    else
        printf("�G���[���������܂����B�Ή�����v���C�l������͂��Ă��������B(4�`10)");
    printf("\n");
}