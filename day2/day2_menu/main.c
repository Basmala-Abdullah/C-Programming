#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define EXTEND_KEY -32
#define BLUE "\033[36m"
#define RESET "\033[0m"

#define NEW_OPTION 0
#define DISPLAY_OPTION 1
#define EXIT_OPTION 2

void forColoringText(){
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif

    // Enable virtual terminal processing
    // Enable virtual terminal processing
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error getting console handle\n");
        return 1;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        fprintf(stderr, "Error getting console mode\n");
        return 1;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        fprintf(stderr, "Error setting console mode\n");
        return 1;
    }
}




void myMenu(){

    int curr_option = NEW_OPTION;
    //save current option as new

    while(1){
        char ch=0;
        ch=getch();
        //printf("%d\n",ch);
        if(ch == EXTEND_KEY){
            ch=getch();
            switch(ch){

            case 72: //UP
                //check the option we are on (the current option)
                /*
                if the current option is new then color the above option as blue and reset the new option, and so on for the rest
                */
                switch (curr_option){
                    case NEW_OPTION:
                        curr_option = EXIT_OPTION;
                        system("cls");
                        color_option(EXIT_OPTION);
                    break;
                     case DISPLAY_OPTION:
                        curr_option = NEW_OPTION;
                        system("cls");
                        color_option(NEW_OPTION);
                    break;
                     case EXIT_OPTION:
                        curr_option = DISPLAY_OPTION;
                        system("cls");
                        color_option(DISPLAY_OPTION);
                    break;
                     default:
                        ;
                }
                break;
            case 77: //Right
                break;
            case 75: //Left
                break;
            case 80: //Down
                //check the option we are on (the current option)
                /*
                if the current option is new then color the below option as blue and reset the new option, and so on for the rest
                */
               switch (curr_option){
                    case NEW_OPTION:
                        curr_option = DISPLAY_OPTION;
                        color_option(DISPLAY_OPTION);
                    break;
                     case DISPLAY_OPTION:
                        curr_option = EXIT_OPTION;
                        color_option(EXIT_OPTION);
                    break;
                     case EXIT_OPTION:
                        curr_option = NEW_OPTION;
                        color_option(NEW_OPTION);
                    break;
                     default:
                        ;
               }
                break;

            default:
                ;
            }
        }else{

            switch(ch){

            case 27: //Exit
                return;
                break;
            case 13: //Enter
                //check current_option
                /*
                if new then call function option_new
                if display then call function option_display
                if exit then return
                */
                switch (curr_option){
                    case NEW_OPTION:
                        option_new();
                        color_option(NEW_OPTION);
                    break;
                     case DISPLAY_OPTION:
                        option_display();
                        color_option(DISPLAY_OPTION);
                    break;
                     case EXIT_OPTION:
                        return;
                    break;
                     default:
                        ;
               }
                break;
            default:
                ;
            }

        }


    }

}

void option_new(){

    /*
    display a page contains new new
    char ch=0;
    ch=getch();
    wait to get char exit then return
    */
    system("cls");
    printf("\033[31mNew\033[0m\n");
    char ch=0;
    while(ch != 27){
        ch=getch();
    }

}

void option_display(){
    /*
    display a page fiha display
    char ch=0;
    ch=getch();
    wait to get char exit then return
    */
    system("cls");
    printf("\033[31mDisplay\033[0m\n");
    char ch=0;
    while(ch != 27){
        ch=getch();
    }

}


void color_option(int option){
    system("cls");
    if(option == NEW_OPTION){
        printf(BLUE"New\033[0m\n");
        printf(RESET"Display\033[0m\n");
        printf(RESET"EXIT\033[0m\n");

    }else if(option == DISPLAY_OPTION){
        printf(RESET"New\033[0m\n");
        printf(BLUE"Display\033[0m\n");
        printf(RESET"EXIT\033[0m\n");
    }
    else if(option == EXIT_OPTION){
        printf(RESET"New\033[0m\n");
        printf(RESET"Display\033[0m\n");
        printf(BLUE"EXIT\033[0m\n");

    }
}





int main()
{
    forColoringText();
    color_option(NEW_OPTION);

    myMenu();


    return 0;
}
