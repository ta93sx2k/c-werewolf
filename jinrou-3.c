#include <stdio.h>
#include <stdlib.h>


void tejun_hyouji(int);
int yakusyoku_haibun(int, int, int);
int main(void)
{
    int num , i;
    int a[16];
    char* name[16];
    srand((unsigned)time( NULL ));
    printf("Please input the number of people of the player.(11~16) ");
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
        
        yakusyoku_haibun(i, num, a[16]);
        
        for(i=0; i<num; i++)
        {
            if(a[i]==1 || a[i]==2 || a[i]==3 || a[i]==4 || a[i]==5 || a[i]==15)
            printf("%s is villager.",&name[i]);
            else if(a[i]==6 || a[i]==7 || a[i]==16)
            printf("%s is werewolf.", &name[i]);
            else if(a[i]==8)
            printf("%s is fortune-teller.", a[i]);
            else if(a[i]==9)
            printf("%s is medium.", &name[i]);
            else if(a[i]==10)
            printf("%s is maniac.", &name[i]);
            else if(a[i]==11)
            printf("%s is hunter.", &name[i]);
            else if(a[i]==12 || a[i]==13)
            printf("%s is co‐owner.", &name[i]);
            else if(a[i]==14)
            printf("%s is fox", &name[i]);
            printf("\n");
        }

    }
    
    return 0;
}

void tejun_hyouji(int num)
{
    if(num==11)
            printf("The post is 5 villagers, 2 werewolfs, fortune-teller, medium, maniac, hunter.");
        else if(num==12)
            printf("The post is 6 villagers, 2 werewolfs, fortune-teller, medium, maniac, hunter.");
        else if(num==13)
            printf("The post is 5 villagers, 2 werewolfs, fortune-teller, medium, maniac, hunter, 2 co-owners.");
        else if(num==14)
            printf("The post is 5 villagers, 2 werewolfs, fortune-teller, medium, maniac, hunter, 2 co-owners, fox.");
        else if(num==15)
            printf("The post is 6 villagers, 2 werewolfs, fortune-teller, medium, maniac, hunter, 2 co-owners, fox.");
        else if(num==16)
            printf("The post is 6 villagers, 3 werewolfs, fortune-teller, medium, maniac, hunter, 2 co-owners, fox.");
        else 
            printf("An error occurred.\nPlease input the play number of people once again.");
    
    printf("\n");
}

int yakusyoku_haibun(int i, int num, int a[16])
{
    for(i=0; i<num; i++)
    {
        return a[i] = rand()%num+1;
    }
}