#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{

    char name[20];
    unsigned int code;
    unsigned int salary;

}Employee;




int main()
{
    Employee e;

    printf("Enter New Employee Code:\n");
    scanf("%d",&e.code);

    printf("Enter New Employee Name:\n");
    scanf("%s",e.name);

    printf("Enter New Employee Salary:\n");
    scanf("%d",&e.salary);

    printf("\nEmployee Code is %d \n",e.code);
    printf("Employee name is %s \n",e.name);
    printf("Employee salary is %d \n",e.salary);

    return 0;
}
