#include <stdio.h>
#include <stdlib.h>



void swap(int *a, int *b) {
    *a +=*b;  //a>b and a -> a+b
    *b=*a-*b; //a>b so b= a-b and b = (a+b)-b -> b=a & a = (a+b)
    *a-=*b; //a = (a+b) - b(after being changed) -> (a+b) - a -> a = b(before being changed) -> successfully swapped
}


void swap2(int *a, int *b) {
    (*a)*=(*b);     //value a is multiplied by b so a is not a * b
    (*b)=(*a)/(*b); //(a*b) is divided by b so b now is a
    (*a)/=(*b); //(a*b) is divided by a so a now is b -> successfully swapped
}


void swap3(int *a, int *b) {
    (*a)^= (*b); //a is now a^b
    (*b)=(*a)^(*b); //b is now a^b^b which is a
    (*a)^=(*b); //a is now a^b^a which is b -> successfully swapped
}

int main()
{
    int x =6;
    int y=4;
    printf("Before Swapping: X= %d, Y=%d\n",x,y);
    swap(&x,&y);
    printf("Swap 1: X= %d, Y=%d\n",x,y);
    swap2(&x,&y);
    printf("Swap 2: X= %d, Y=%d\n",x,y);
    swap3(&x,&y);
    printf("Swap 3: X= %d, Y=%d\n",x,y);

    return 0;
}
