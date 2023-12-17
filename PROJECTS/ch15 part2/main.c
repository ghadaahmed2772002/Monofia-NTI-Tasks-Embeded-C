#include <stdio.h>
#include <stdlib.h>


int main()
{
    char name[50];
    int emp_id, dep_id;
    float salary;
    FILE *empptr = NULL;
    char op;

    printf("Enter 'c' to create or 'a' to append: ");
    scanf(" %c", &op);

    if (op == 'c')
    {
        empptr = fopen("D://employeeData.csv", "w");
        printf("File created.\n ");
        if (empptr == NULL)
        {
            printf("Cannot open file.\n");
            exit(1);
        }
        fprintf(empptr,"%s, %s, %s, %s \n","employeeID","employeeName","employeeSalary","departmentID");
    }
    else if (op == 'a')
    {
        empptr = fopen("D://employeeData.csv", "a");
        if (empptr == NULL)
        {
            printf("Cannot open file.\n");
            exit(1);
        }
        fprintf(empptr, "%d,%s,%f,%d\n", 4, "ghada", 200.4, 7);
    }

    while (1)
    {
        char choice;
        printf("Enter 'y' to continue or 'n' to exit: ");
        scanf(" %c", &choice);

        if (choice == 'y')
        {
            printf("Enter employee data (employeeID name salary department): ");
            scanf("%d %s %f %d", &emp_id, name, &salary, &dep_id);

            if (empptr != NULL)
            {
                fprintf(empptr, "%d,%s,%f,%d\n", emp_id, name, salary, dep_id);
                rewind(empptr);
                /*int x,w;
                float z;
                char y[50],ca;
                while(!feof(empptr)){
                     ca=fgetc(empptr);
                     if(ca=='\n'){
                            fscanf(empptr,%d,&x);




                     }




                }*/




            }
            else
            {
                printf("File pointer is NULL.\n");
            }
        }
        else if (choice == 'n')
        {
            break;
        }
    }

    if (empptr != NULL)
    {
        fclose(empptr);
    }

    return 0;
}
