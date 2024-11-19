#include <stdio.h>
#include <stdlib.h>

int calculatePowerXY(int x, int y){

    if(y==0)
        return 1;

    return x*calculatePowerXY(x,y-1);

}


int main()
{
    int x=0,y=0;
    printf("Enter a 2 numbers:\n");
    scanf("%d %d", &x,&y);
    if(y<0){
        printf("Second number should be positive\n");
        return -1;
    }
    printf("Result of the power: %d\n", calculatePowerXY(x,y));
    return 0;
}
