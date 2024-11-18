#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1;
    char y = 'B';
    float z = 0.5;

    ///////////////////////////////Write a C program to test the different format specifiers with "printf"///////////////////////////////

    //Printng String
    printf("Hello World\n");

    //Printing values of x, y, and z
    printf("x=%d \t y=%c \t z=%0.2f\n",x,y,z);

    //Printing ASCII value of y (can automatically cast from character to its ASCII integer value)
    printf("ASCII value of y = %d\n",y);

    //Printing character equivalent to ASCII value of y+x (can automatically cast from ASCII integer value to its character)
    printf("char of (y+x) = %c\n",y+x);

    //Printing float
    printf("x+z = %f\n", x+z);

    printf("\nCannot automatically cast from float to integer or vice versa:\n");
    printf("x+z = %d\n", x+z); //didn't find an integer so printed 0
    printf("x = %f\n", x); //didn't find an float so printed 0.000

    ///////////////////////////////Write a C program to read a character from the user and print it and its ASCII code///////////////////////////////
    char input;
    printf("Enter character value:\n");
    scanf("%c",&input);
    printf("user input = %c, and its ASCII value = %d\n",input,input);

    ///////////////////////////////Write a C program to display the octal and the hexadecimal representation of an integer number///////////////////////////////
    int number=64;
    printf("number octal value  = %o, number hexadecimal value  = %x\n",number,number);

    return 0;
}
