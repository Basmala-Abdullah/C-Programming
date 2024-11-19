#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4




void userMatrix(){

    float matrix[ROWS][COLS]={0};

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("Enter value for matrix[%d][%d]: ", i , j );

            if (scanf("%f", &matrix[i][j]) != 1) {
                printf("Error: Invalid input. Numeric values only.\n");
                return;
            }
        }
    }

    float sum = 0;
    for(int i=0;i<ROWS;i++){
        sum = (matrix[i][0]+ matrix[i][1]+ matrix[i][2]+matrix[i][3]);
        printf("Sum of row no %d= %f\n",i,sum);
    }

    for(int i=0;i<COLS;i++){
        sum = (matrix[0][i]+ matrix[1][i]+ matrix[2][i]);
        float avg = sum/3.0;
        printf("Avg of col no %d= %f\n",i,avg);
    }
}


int main()
{
    printf("Enter Values of Matrix 3*4\n\n");
    userMatrix();

    return 0;
}
