#include <stdio.h>

int main(void)
{
    int i;
    char* name[100];
    
    for(i=0; i<4; i++)
    {
        printf("Please your name. ");
        scanf("%s", &name[i]);
    }
    for(i=0; i<4; i++)
    {
        printf("%s\n", &name[i]);
    }
    
    return 0;
}