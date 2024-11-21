#include <stdio.h>
#include <stdlib.h>


#define ROWS 3
#define COLS 4

int checkString(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(atof(&str[i])==0){
            return -1;
        }
        i++;
    }
    return 1;
}


void userMatrix(){

    float matrix[ROWS][COLS]={0};

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            char str[20];
            gets(str);

            //printf("str[0]=%c, str[1]=%c",str[0],str[1] );
            if(str[0] == '0' && str[1] == '\0'){
                matrix[i][j]=0;
            }
            else{
                /*int len = strlen(str);
                float checkLast = atof(&str[len-1]);
                float num1 = atof(str);
                if(num1 ==0 || checkLast==0){
                    printf("Error: Invalid input. Numeric values only.\n");
                    return;
                }
                matrix[i][j]=num1;*/
                if(checkString(str)==-1){
                    printf("Error: Invalid input. Numeric values only.\n");
                    return;
                }
                float num1 = atof(str);
                matrix[i][j]=num1;
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
    //printf("%f\n",num1);
}





int main()
{

    printf("Enter 12 Values for Matrix 3*4\n\n");
    userMatrix();

    return 0;
}
