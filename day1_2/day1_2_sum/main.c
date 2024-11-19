#include <stdio.h>
#include <stdlib.h>


void recieveNum(){
    int sum=0;
    int input;
    while(sum<=100){
        scanf("%d",&input);
        sum+=input;
    }
}

int main()
{   printf("Enter numbers\n");
    recieveNum();
    return 0;
}
