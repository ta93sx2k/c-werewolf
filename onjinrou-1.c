#include <stdio.h>

void ninzu_nyuryoku(int);

int main (void)
{
    int num, i, j;
    char name[10][50];
    
    printf("�v���C�l������͂��Ă��������B(4�`10)��");
    scanf("%d", &num);
        
    ninzu_nyuryoku(num);
    
    if(num==4 || num==5 || num==6 || num==7 || num==8 || num==9 || num==10)
    {
        printf("���O����͂��Ă��������B\n");
        
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
            printf("�v���C���[%d:" ,i+1);
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