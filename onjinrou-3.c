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
    
    printf("�v���C�l������͂��Ă��������B(4�`10)��");
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
                printf("player%2d:���Ȃ��̖�E�͑��l�ł��B\n", player_number[i]);
            else if(yakusyoku[i]==3 || yakusyoku[i]==4 || yakusyoku[i]==9)
                printf("player%2d:���Ȃ��̖�E�͐l�T�ł��B\n", player_number[i]);
            else if (yakusyoku[i]==5)
                printf("player%2d:���Ȃ��̖�E�͐肢�t�ł��B\n", player_number[i]);
            else if (yakusyoku[i]==6)
                printf("player%2d:���Ȃ��̖�E�͉����ł��B\n", player_number[i]);
            else if (yakusyoku[i]==8)
                printf("player%2d:���Ȃ��̖�E�͒ݐl(�Ă�Ă�)�ł��B\n", player_number[i]);
                
        }
        printf("\n");
        
        for(i=1; i<=num; i++)
        {
            if(yakusyoku[i]==1 || yakusyoku[i]==2 || yakusyoku[i]==7 || yakusyoku[i]==10 || yakusyoku[i]==11 || yakusyoku[i]==12)
                printf("player%2d:���l�͋c�_�����Đl�T��T���Ă��������B\n", player_number[i]);
            
            if(yakusyoku[i]==3 || yakusyoku[i]==4 || yakusyoku[i]==9)
            {
                if(yakusyoku[i]==3)
                {
                    printf("player%2d:�l�T�͒��ԂƋ��͂��đ��l���x���Ă��������B\n", player_number[i]);
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==4)
                            printf("         ���Ԃ�player%2d�ł��B\n", player_number[j]);
                    }
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==9)
                            printf("         ���Ԃ�player%2d�ł��B\n", player_number[j]);
                    }
                    if((yakusyoku[num+1]==4 || yakusyoku[num+2]==4) && (yakusyoku[num+1]==9 || yakusyoku[num+2]==9))
                        printf("         ���Ԃ͂��܂���ł����B\n");
                }
                if(yakusyoku[i]==4)
                {
                    printf("player%2d:�l�T�͒��ԂƋ��͂��đ��l���x���Ă��������B\n", player_number[i]);
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==3)
                            printf("         ���Ԃ�player%2d�ł��B\n", player_number[j]);
                    }
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==9)
                            printf("         ���Ԃ�player%2d�ł��B\n", player_number[j]);
                    }
                    if((yakusyoku[num+1]==3 || yakusyoku[num+2]==3) && (yakusyoku[num+1]==9 || yakusyoku[num+2]==9))
                        printf("         ���Ԃ͂��܂���ł����B\n");
                }
                if(yakusyoku[i]==9)
                {
                    printf("player%2d:�l�T�͒��ԂƋ��͂��đ��l���x���Ă��������B\n", player_number[i]);
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==3)
                            printf("         ���Ԃ�player%2d�ł��B\n", player_number[j]);
                    }
                    for(j=1; j<=num; j++)
                    {
                        if(yakusyoku[j]==4)
                            printf("         ���Ԃ�player%2d�ł��B\n", player_number[j]);
                    }
                    if((yakusyoku[num+1]==3 || yakusyoku[num+2]==3) && (yakusyoku[num+1]==4 || yakusyoku[num+2]==4))
                        printf("         ���Ԃ͂��܂���ł����B\n");
                }
            }
        
            if(yakusyoku[i]==5)
            {
                printf("player%2d:�肢�t�̓v���C���[�̖�E�A�������͑I�΂�Ă��Ȃ���E�����邱�Ƃ��ł��܂��B(0)\n", player_number[i]);
                printf("         �肢�����v���C���[�̃v���C���[�ԍ�����͂��Ă��������B(0�`%d)��", num);
                scanf("%d", &uranai);
                if(uranai==num || uranai==num-1 || uranai==num-2 || uranai==num-3 || uranai==num-4 || uranai==num-5 || uranai==num-6 || uranai==num-7 || uranai==num-8 || uranai==num-9 && uranai!=5)
                { 
                    if(yakusyoku[uranai]==1 || yakusyoku[uranai]==2 || yakusyoku[uranai]==7 || yakusyoku[uranai]==11 || yakusyoku[uranai]==12)
                        printf("         player%2d�̖�E�͑��l�ł��B\n", player_number[uranai]);
                    else if(yakusyoku[uranai]==3 || yakusyoku[uranai]==4 || yakusyoku[uranai]==9)
                        printf("         player%2d�̖�E�͐l�T�ł��B\n", player_number[uranai]);
                    else if(yakusyoku[uranai]==6)
                        printf("         player%2d�̖�E�͉����ł��B\n", player_number[uranai]);
                    else if(yakusyoku[uranai]==8)
                        printf("         player%2d�̖�E�͒ݐl(�Ă�Ă�)�ł��B\n", player_number[uranai]);
                }
                if(uranai==0 && uranai!=5)
                {
                    if(yakusyoku[num+1]==1 || yakusyoku[num+1]==2 || yakusyoku[num+1]==7 || yakusyoku[num+1]==11 || yakusyoku[num+1]==12)
                        printf("         �I�΂�Ă��Ȃ���E�͑��l�ł��B\n");
                    else if(yakusyoku[num+1]==3 || yakusyoku[num+1]==4 || yakusyoku[num+1]==9)
                        printf("         �I�΂�Ă��Ȃ���E�͐l�T�ł��B\n");
                    else if(yakusyoku[num+1]==6)
                        printf("         �I�΂�Ă��Ȃ���E�͉����ł��B\n");
                    else if(yakusyoku[num+1]==8)
                        printf("         �I�΂�Ă��Ȃ���E�͒ݐl(�Ă�Ă�)�ł��B\n");
                }
                if(uranai==0 && uranai!=5)
                {
                    if(yakusyoku[num+2]==1 || yakusyoku[num+2]==2 || yakusyoku[num+2]==7 || yakusyoku[num+2]==11 || yakusyoku[num+2]==12)
                        printf("         �I�΂�Ă��Ȃ���E�͑��l�ł��B\n");
                    else if(yakusyoku[num+2]==3 || yakusyoku[num+2]==4 || yakusyoku[num+2]==9)
                        printf("         �I�΂�Ă��Ȃ���E�͐l�T�ł��B\n");
                    else if(yakusyoku[num+2]==6)
                        printf("         �I�΂�Ă��Ȃ���E�͉����ł��B\n");
                    else if(yakusyoku[num+2]==8)
                        printf("         �I�΂�Ă��Ȃ���E�͒ݐl(�Ă�Ă�)�ł��B\n");
                }
            }
        
            if(yakusyoku[i]==6)
            {
                printf("player%2d:�����͑��v���C���[�Ɩ�E���������邱�Ƃ��ł��܂��B\n", player_number[i]);
                printf("         �����������v���C���[�̃v���C���[�ԍ�����͂��Ă��������B\n         ��E�̌������s�������Ȃ��Ƃ��͎����̃v���C���[�ԍ�����͂��Ă��������B(1�`%d)��", num);
                scanf("%d", &kaitou);
                if(yakusyoku[kaitou]==1 || yakusyoku[kaitou]==2 || yakusyoku[kaitou]==7 || yakusyoku[kaitou]==11 || yakusyoku[kaitou]==12)
                    printf("         ������̂��Ȃ��̖�E�͑��l�ł��B\n", player_number[i]);
                else if(yakusyoku[kaitou]==3 || yakusyoku[kaitou]==4 || yakusyoku[kaitou]==9)
                    printf("         ������̂��Ȃ��̖�E�͐l�T�ł��B\n", player_number[i]);
                else if(yakusyoku[kaitou]==5)
                    printf("         ������̂��Ȃ��̖�E�͐肢�t�ł��B\n", player_number[i]);
                else if(yakusyoku[kaitou]==6)
                    printf("         ��E�̌������s���܂���ł����B\n", player_number[i]);
                else if(yakusyoku[kaitou]==8)
                    printf("         ������̂��Ȃ��̒ݐl(�Ă�Ă�)�ł��B\n", player_number[i]);
            }
            
            if(yakusyoku[i]==8)
                printf("player%2d:�ݐl(�Ă�Ă�)�͐l�T�`�[���ɂ����l�`�[���ɂ������܂���B\n         ���Y���ꂽ�Ƃ��ɏ������܂��B\n", player_number[i]);
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