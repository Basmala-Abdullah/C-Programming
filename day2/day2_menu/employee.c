/*
#include "employee.h"


Employee employees[MAX_EMPLOYEE_SIZE];

char noOfSavedEmployees=0;

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
    char ch;
    while(ch != 27){
        ch=getch();
    }

}


void enterNewEmployeeData(){
    system("cls");
    if(noOfSavedEmployees>5){
        printf("Cannot Enter New Employee Data\n");
        return;
    }

    printf("Enter New Employee Code:\n");
    scanf("%d",&employees[noOfSavedEmployees].code);

    printf("Enter New Employee Name:\n");
    scanf("%s",employees[noOfSavedEmployees].name);

    printf("Enter New Employee Salary:\n");
    scanf("%d",&employees[noOfSavedEmployees].salary);

    noOfSavedEmployees++;

    char ch;
    while(ch != 27){
        ch=getch();
    }
}

*/

