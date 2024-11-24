#include <stdio.h>
#include <conio.h>
#include <string.h>


#define ARRAY_SIZE 100

//cursorPos ranges from 0 to number of characters written int the array
void printBuffer(char *buffer, int cursorPos, int num_char) {
    system("cls");
    for (int i = 0; i < cursorPos; i++) {
        printf("%c", buffer[i]);
    }

    printf("|"); //to print cursor position
    for (int i = cursorPos; i < num_char; i++) {
        printf("%c", buffer[i]);
    }
}

int main()
{

    char buffer[ARRAY_SIZE] = {0}; //buffer initialization
    int cursorPos = 0;            //cursor starts from 0
    int insertMode = 0;           //0 for overwrite, 1 for insert mode
    int cursorISInHome=0;         //flag to check if cursor is in home or not

    while (1) {
        printBuffer(buffer, cursorPos,strlen(buffer));
        char ch = getch();
        if (ch == 27) {   //esc key for exiting
            break;
        }
        //printf("%d\n",ch);
        if (ch == -32) { //Extended key
            ch = getch();
            switch (ch) {
                case 75: //Left
                    //printf("Left\n");
                    if (cursorPos > 0) cursorPos--;
                    break;
                case 77: //Right
                    //printf("Right\n");
                    if (cursorPos < strlen(buffer)) cursorPos++;
                    break;
                case 71: //Home
                    //printf("Home\n");
                    cursorPos = 0;
                    break;
                case 79: //End
                    //printf("End\n");
                    cursorPos = strlen(buffer);
                    break;
                case 83: //Delete
                    //it deletes the character that follows the cursor
                    //printf("Delete\n");
                    for (int i = cursorPos; i < strlen(buffer); i++) {
                        buffer[i] = buffer[i + 1];//
                    }

                    break;
                case 82: //Insert

                    if(insertMode){
                        insertMode=0;
                        //printf("Insert is 0\n");
                    }
                    else{
                        insertMode=1;
                        //printf("Insert is 1\n");
                    }
                    break;
                default:
                    ;

            }
        }else {

            if(ch ==8){
                //it deletes the character the is directly after the cursorPos
                cursorISInHome=0;
                if(cursorPos==0){
                    cursorISInHome=1;
                }
                if (cursorPos > 0) {
                    for (int i = cursorPos - 1; i < strlen(buffer); i++) {
                        buffer[i] = buffer[i + 1];
                    }
                    cursorPos--;
                }

            }else if(ch!=13){

                if(strlen(buffer)<=ARRAY_SIZE-1){
                    if (insertMode) {
                            //printf("you are in insert mode\n");
                            buffer[cursorPos] = ch;
                            cursorPos++;
                    }
                    else{
                        for (int i = strlen(buffer); i >= cursorPos; i--) {
                                buffer[i + 1] = buffer[i];
                        }
                        buffer[cursorPos] = ch;
                        cursorPos++;
                    }
                }
            }


        }
    }
    return 0;
}


