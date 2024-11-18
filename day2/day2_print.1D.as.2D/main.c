#include <stdio.h>
#include <stdlib.h>


#define max_arr_size 10

void printArray(){

    int arr[max_arr_size]={0};
    int rows=0;

    printf("Enter number of rows divisible by %d\n",max_arr_size);
    scanf("%d",&rows);

    if(max_arr_size%rows !=0 || rows<=0){

        printf("Error: wrong number\n");
        return;
    }


    int cols = max_arr_size/rows;

    printf("Enter %d values for the array\n",max_arr_size);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i * cols + j]);
        }
    }

    printf("\nValues of the array:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("  %d",arr[i * cols + j]);
        }
        printf("\n");
    }
}

int main()
{
    printArray();

    return 0;
}
