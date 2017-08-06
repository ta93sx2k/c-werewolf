#include <stdio.h>
int main(void)
{
    int num;
    printf("Please input the number of people of the player.(11~16) \n");
    scanf("%d", &num);

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
            printf("An error occurred.\nPlease input the number of people of the player once again.");
    
    return 0;
}