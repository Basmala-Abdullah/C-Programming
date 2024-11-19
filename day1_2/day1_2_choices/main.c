#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Choose a number:\n");
    printf("Choice 1\n");
    printf("Choice 2\n");
    printf("Choice 3\n");

    int choice=0;
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("Entered Choice 1\n");
        break;
    case 2:
        printf("Entered Choice 2\n");
        break;
    case 3:
        printf("Entered Choice 3\n");
        break;
    default:
        printf("Invalid Choice\n");
    }
    return 0;
}
