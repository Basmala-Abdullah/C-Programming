#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


//to move the cursor to a specific position (x, y) in the console
void gotoxyl(int x, int y) {
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void generateMagicBox(int n) {
    int i=0;
    int j=n/2;
    int cellWidthLength=4;
    for (int num=1; num<=n*n;num++) {
        gotoxyl(j*cellWidthLength,i);
        Sleep(50);
        printf("%d",num);

        if (num%n!=0) {
            i--; //decrementing row
            j--; //decrementing col
            if (i<0)
                i = n - 1;   //wrap row to bottom
            if (j<0)
                j = n - 1;   //wrap column to right
        } else {
            i++;
            if (i==n) i = 0;//wrap around
        }
    }
}

int main() {
    int n=0;
    scanf("%d", &n);

    //Checking if the input size is valid (must be an odd number)
    if (n%2 == 0) {
        printf("Error: Size should be an odd number.");
        return -1;
    }

    generateMagicBox(n);
    return 0;
}
