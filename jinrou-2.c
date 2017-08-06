#include <stdio.h>
void tejun_hyouji(int);
int main(void)
{
    int num , i;
    int a[16];
    char* name[16];
    printf("プレイ人数を入力して下さい。(11~16)=> ");
    scanf("%d", &num);
    
    tejun_hyouji(num);
    
    if(num==11 || num==12 || num==13 || num==14 || num==15 || num==16)
    {
        for(i=0; i<num; i++)
        {
            printf("please your name. ");
            scanf("%s", &name[i]);
            printf("%s\n",&name[i]);
        }

    }
    
    return 0;
}

void tejun_hyouji(int num)
{
 if(num==11)
            printf("The post is 5 villagers, 2 were-wolfs, fortune-teller, medium, maniac, hunter.");
        else if(num==12)
            printf("The post is 6 villagers, 2 were-wolfs, fortune-teller, medium, maniac, hunter.");
        else if(num==13)
            printf("The post is 5 villagers, 2 were-wolfs, fortune-teller, medium, maniac, hunter, 2 co-owners.");
        else if(num==14)
            printf("The post is 5 villagers, 2 were-wolfs, fortune-teller, medium, maniac, hunter, 2 co-owners, fox.");
        else if(num==15)
            printf("The post is 6 villagers, 2 were-wolfs, fortune-teller, medium, maniac, hunter, 2 co-owners, fox.");
        else if(num==16)
            printf("The post is 6 villagers, 3 were-wolfs, fortune-teller, medium, maniac, hunter, 2 co-owners, fox.");
        else 
            printf("An error occurred.\nPlease input the play number of people once again.");
    
    printf("\n");
}