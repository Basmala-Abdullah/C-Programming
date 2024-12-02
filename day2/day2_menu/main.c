#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
//#include "employee.h"

#define EXTEND_KEY -32
#define BLUE "\033[36m" //for blue text
#define RESET "\033[0m" //to reset text formatting
#define GREEN "\033[32m"

#define NEW_OPTION 0
#define DISPLAY_OPTION 1
#define MODIFY_OPTION 2
#define DELETE_OPTION 3
#define EXIT_OPTION 4

#define MAX_EMPLOYEE_SIZE 5


typedef struct Employee{

    char name[20];
     int code;
     int salary;

}Employee;
//Prototypes
void displayIDs();
void halt_untilESC();
int contains_only_characters(char *str);
int is_numeric(const char *str);
int checkIDUniqueness(int code_toBeChecked);
void enterNewEmployeeData();
void deleteEmployee();
void displayEmployees(Employee e[], int size);
void displayIDs();
void modifyEmployee();
//to enable virtual terminal processing for colored text support
void forColoringText(){
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif


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



void halt_untilESC(){
    char ch;
    while(ch != 27){
        ch=getch();
    }
}


//////////////////////////////////////////////Employee Functions//////////////////////////////////////////////


Employee employees[MAX_EMPLOYEE_SIZE];

char noOfSavedEmployees=0;

int contains_only_characters(char *str) {
    if (str == NULL) return 0; // Null check

    while (*str) {
        if (!(isalpha(*str)|| *str == ' ')) {
            return 0; //non-alphabetic character found
        }
        str++;
    }
    return 1; //all characters are alphabetic
}
int is_numeric(const char *str) {
    if (str == NULL || *str == '\0') return 0; // Null or empty string check

    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Non-numeric character found
        }
        str++;
    }
    return 1; // All characters are numeric
}



int checkIDUniqueness(int code_toBeChecked){

    char employee_unique =1; //flag to check if the employee id is unique or not

    for(int i=0; i<noOfSavedEmployees && employee_unique;i++){
        if(employees[i].code == code_toBeChecked){
            employee_unique=0;
        }

    }
    return employee_unique;
}

void enterNewEmployeeData(){

    system("cls");
    if(noOfSavedEmployees==MAX_EMPLOYEE_SIZE){
        printf("Cannot Enter New Employee Data\n");
    }
    else{
        int empolyee_input_code;

        printf("Enter New Employee Code:\n");
        char id[20];
        scanf("%s",id);
        if(!is_numeric(id)){
            printf("Enter numbers only\n");
            return;
        }else{
            empolyee_input_code = atoi(id);
        }

        if(!checkIDUniqueness(empolyee_input_code)){
            printf("Code already exists!!\n");
            return;
        }
        employees[noOfSavedEmployees].code=empolyee_input_code;
        printf("Enter New Employee Name:\n");
        scanf("\n%[^\n]s",employees[noOfSavedEmployees].name);

        if(!contains_only_characters(employees[noOfSavedEmployees].name)){
            printf("Name is invalid, only characters\n");
            return;
        }
        int esalary=0;
        printf("Enter New Employee Salary:\n");
        char salary[20];
        scanf("%s",salary);
        if(!is_numeric(salary)){
            printf("Enter numbers only\n");
            return;
        }else{
            esalary = atoi(salary);
        }
        employees[noOfSavedEmployees].salary=esalary;

        noOfSavedEmployees++;
        printf(GREEN "Employee Data is Saved Successfully!\n" RESET);


    }

}

void deleteEmployee(){

    system("cls");
    displayIDs();
    if(noOfSavedEmployees == 0){
        //printf("\033[31mNo employees to delete\033[0m\n");
        return;
    }

    int empolyee_input_code=-1;

    printf("Enter employee code to be deleted:\n");
    char id[20];
    scanf("%s",id);
    if(!is_numeric(id)){
        printf("Enter numbers only\n");
        return;
    }else{
        empolyee_input_code = atoi(id);
    }
    if(checkIDUniqueness(empolyee_input_code)){
       printf("\033[31mNo employee of that ID\033[0m\n");
       return;
    }

    int index_employeeToBeDeleted=-1;

    for(int i=0;i<noOfSavedEmployees && index_employeeToBeDeleted==-1;i++){
        if(employees[i].code == empolyee_input_code){
            index_employeeToBeDeleted=i;
        }
    }


    if(index_employeeToBeDeleted != -1){
        for(int i= index_employeeToBeDeleted; i < noOfSavedEmployees-1; i++){
            employees[i].code = employees[i+1].code;
            strcpy(employees[i].name, employees[i+1].name);
            employees[i].salary = employees[i+1].salary;
        }
    }
    noOfSavedEmployees--;
    printf(GREEN "Employee Data is Deleted!\n" RESET);

}


void displayEmployees(Employee e[], int size){
    system("cls");
    if(size ==0){
        printf("\033[31mNo employees\033[0m\n");
    }

    for(int i=0;i<size;i++){
        printf("Employee Code is %d \n",e[i].code);
        printf("Employee name is %s \n",e[i].name);
        printf("Employee salary is %d \n",e[i].salary);
        printf("______________________________\n");
    }
}

void displayIDs(){
    system("cls");
    if(noOfSavedEmployees ==0){
        printf("\033[31mNo employees\033[0m\n");
    }
     for(int i=0;i<noOfSavedEmployees;i++){
        printf("Employee Code is %d \n",employees[i].code);
        printf("______________________________\n");
    }

}

void modifyEmployee(){
    int id_toBeModified;

    displayIDs();
    if(!noOfSavedEmployees){
        return;
    }
    printf("Enter the employee ID you want to modify:\n");
    char employee_id[20];
    scanf("%s",employee_id);
    if(!is_numeric(employee_id)){
        printf("Enter numbers only\n");
        return;
    }else{
        id_toBeModified = atoi(employee_id);
    }

    char employee_index=-1;//to save the index of the required employee in the array
    //char employee_found =0; //flag to check if the employee is found
    for(int i=0; i<noOfSavedEmployees && employee_index == -1; i++){
        if(employees[i].code == id_toBeModified){
            employee_index=i;
        }
    }
    int empolyee_input_code;
    if(employee_index!=-1){
        /*
        printf("Enter New Employee Code:\n");
        scanf("%d",&empolyee_input_code);
        if(!checkIDUniqueness(empolyee_input_code)){
            printf("Code already exists!!\n");
            return;
        }
        employees[employee_index].code = empolyee_input_code;
        printf("Enter New Employee Name:\n");
        scanf("%s",employees[employee_index].name);

        printf("Enter New Employee Salary:\n");
        scanf("%d",&employees[employee_index].salary);
        */

        printf("Enter 1 to modify the employee code\nEnter 2 to modify employee name\nEnter 3 to modify employee salary\n");
        int userChoiceTomodify;
        scanf("%d",&userChoiceTomodify);

        switch(userChoiceTomodify){
        case 1:
            printf("Enter New Employee Code:\n");
            char id[20];
            scanf("%s",id);
            if(!is_numeric(id)){
                printf("Enter numbers only\n");
                return;
            }else{
                empolyee_input_code = atoi(id);
            }

            if(!checkIDUniqueness(empolyee_input_code)){
                printf("Code already exists!!\n");
                return;
            }
            employees[employee_index].code=empolyee_input_code;
            break;
        case 2:
            printf("Enter Employee New Name:\n");
            char name[20];
            scanf("%s",name);
            if(!contains_only_characters(name)){
                printf("Name is invalid, characters only\n");
                return;
            }
            else{
                strcpy(employees[employee_index].name,name);
            }
            break;
        case 3:

            printf("Enter New Employee Salary:\n");
            char salary[20];
            scanf("%s",salary);
            int esalary=0;
            if(!is_numeric(salary)){
                printf("Enter numbers only\n");
                return;
            }else{
                esalary = atoi(salary);
            }
            employees[employee_index].salary=esalary;
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    }
    else{
        printf("No employee of that ID\n");
        return;
    }
    printf(GREEN "Employee Data is Modified!\n" RESET);
}



///////////////////////////////////////////////////////////

void myMenu(){
    //initializing the initial state of the current menu option
    //save current option as new
    int curr_option = NEW_OPTION;


    while(1){

        char ch=0;
        ch=getch();

        if(ch == EXTEND_KEY){
            ch=getch();
            //printf("%d\n",ch);
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
                    case MODIFY_OPTION:
                        curr_option = DISPLAY_OPTION;
                        system("cls");
                        color_option(DISPLAY_OPTION);
                    break;
                    case DELETE_OPTION:
                        curr_option = MODIFY_OPTION;
                        system("cls");
                        color_option(MODIFY_OPTION);
                    break;
                     case EXIT_OPTION:
                        curr_option = DELETE_OPTION;
                        system("cls");
                        color_option(DELETE_OPTION);
                    break;
                     default:
                        ;
                }
                break;
            case 77: //Right
                break;
            case 75: //Left
                break;
            case 71: //Home
                initial_state();
                curr_option = NEW_OPTION;
                color_option(NEW_OPTION);
                break;
            case 79: //End
                initial_state();
                curr_option = EXIT_OPTION;
                color_option(EXIT_OPTION);
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
                        curr_option = MODIFY_OPTION;
                        color_option(MODIFY_OPTION);
                    break;
                    case MODIFY_OPTION:
                        curr_option = DELETE_OPTION;
                        color_option(DELETE_OPTION);
                    break;
                    case DELETE_OPTION:
                        curr_option = EXIT_OPTION;
                        system("cls");
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
                        enterNewEmployeeData();
                        halt_untilESC();
                        initial_state();
                        color_option(NEW_OPTION);
                    break;
                     case DISPLAY_OPTION:
                        displayEmployees(employees,noOfSavedEmployees);
                        halt_untilESC();
                        initial_state();
                        color_option(DISPLAY_OPTION);
                    break;
                     case MODIFY_OPTION:
                         modifyEmployee();
                         halt_untilESC();
                         initial_state();
                        color_option(MODIFY_OPTION);
                    break;
                    case DELETE_OPTION:
                         deleteEmployee();
                         halt_untilESC();
                         initial_state();
                        color_option(DELETE_OPTION);
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

/*
void option_new(){


    //display a page contains new new
    //char ch=0;
    //ch=getch();
    //wait to get char exit then return

    system("cls");
    printf("\033[31mNew\033[0m\n");
    char ch=0;
    while(ch != 27){
        ch=getch();
    }

}

void option_display(){

    //display a page fiha display
    //char ch=0;
    //ch=getch();
    //wait to get char exit then return

    system("cls");
    printf("\033[31mDisplay\033[0m\n");
    char ch=0;
    while(ch != 27){
        ch=getch();
    }

}
*/

void color_option(int option){
    system("cls");
    if(option == NEW_OPTION){
        printf(BLUE"New\033[0m\n");
        printf(RESET"Display\033[0m\n");
        printf(RESET"Modify\033[0m\n");
        printf(RESET"Delete\033[0m\n");
        printf(RESET"EXIT\033[0m\n");

    }else if(option == DISPLAY_OPTION){
        printf(RESET"New\033[0m\n");
        printf(BLUE"Display\033[0m\n");
        printf(RESET"Modify\033[0m\n");
        printf(RESET"Delete\033[0m\n");
        printf(RESET"EXIT\033[0m\n");
    }
    else if(option == MODIFY_OPTION){
        printf(RESET"New\033[0m\n");
        printf(RESET"Display\033[0m\n");
        printf(BLUE"Modify\033[0m\n");
        printf(RESET"Delete\033[0m\n");
        printf(RESET"EXIT\033[0m\n");
    }
    else if(option == DELETE_OPTION){
        printf(RESET"New\033[0m\n");
        printf(RESET"Display\033[0m\n");
        printf(RESET"Modify\033[0m\n");
        printf(BLUE"Delete\033[0m\n");
        printf(RESET"EXIT\033[0m\n");
    }
    else if(option == EXIT_OPTION){
        printf(RESET"New\033[0m\n");
        printf(RESET"Display\033[0m\n");
        printf(RESET"Modify\033[0m\n");
        printf(RESET"Delete\033[0m\n");
        printf(BLUE"EXIT\033[0m\n");
    }
}

void initial_state(){
    system("cls");
    forColoringText();
    color_option(NEW_OPTION);
}



int main()
{
    initial_state();
    myMenu();

    return 0;
}
