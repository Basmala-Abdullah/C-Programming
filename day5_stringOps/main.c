#include <stdio.h>
#include <stdlib.h>

int my_strLen(char str[]){
    unsigned int i=0;
    while(str[i] != '\0'){

        i++;
    }
    return i;
}


void my_strcat(char dest[], char source[]){

    int i=0;
    int j=0;

    while(dest[i]!= '\0'){
        i++;
    }
    while(source[j]!='\0'){
        dest[i]=source[j];
    }
}

int my_strcmp(char str1[], char str2[]){

    int index=0;

    while(str1[index]==str2[index] && str1[index]!='\0'){
            index++;

    }
    int len1 = my_strLen(str1);
    int len2 = my_strLen(str2);
    if(index == len1 && len1 == len2 ){
        return 0;
    }
    else{

        return (str1[index]-str2[index]);
    }

}



void my_strcpy(char dest[], char src[], int size){
    int i=0;
    if(my_strLen(src) <= size){
        while(src[i] != '\0'){
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    else{
        printf("Error: Source Size is more than the destination size");
    }
}

void my_toUpperCase(char str[]) {
    unsigned int i=0;
    while (str[i]!='\0') {
        if (str[i]>='a' && str[i]<='z') {
            str[i]=str[i]-('a'-'A');
        }
        i++;
    }
}

void my_toLowerCase(char str[]) {
    unsigned int i=0;
    while (str[i]!='\0') {

        if (str[i]>='A'&&str[i]<='Z') {
            str[i]=str[i]+('a'-'A');
        }
        i++;
    }
}

int main()
{




    return 0;
}
