#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 50

// Function declarations
int isIdUnique(char *tablePath, int id);
int isForeignKeyValid(char *tablePath, int foreignKeyId);
void updateRecord(char *tablePath, int id, int n, char col_name[max_size][max_size], char col_type[max_size]);

int main() {
    char operation[10];
    printf("-------------------DataBase Application------------------------------------------\n\n");
    while (1)
        {
                // operation
            printf("Enter Operation ( create | select | insert | update | exit ): ");
            scanf("%s", operation);

               //define columns
            char col_name[max_size][max_size];
            char col_type[max_size];
            char tablePath[max_size];

            int n;
            printf("enter number of columns: ");
            scanf("%d", &n);

            if (strcmp(operation, "create") == 0) {
                printf("enter table path : ");
                scanf("%s", tablePath);

                FILE *ptr = fopen(tablePath, "w");   //write
                if (ptr == NULL) {
                    printf("file path not exist \n");
                    exit(0);
                }
                  //define colunms
                for (int i = 0; i < n; i++) {
                    printf("Enter col name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                    scanf("%s %c", col_name[i], &col_type[i]);
                }
                  //print in file
                for (int i = 0; i < n; i++)
                    {
                       fprintf(ptr, "%s,%c,", col_name[i], col_type[i]);
                    }
                    fprintf(ptr, "\n");
                    fclose(ptr);   //close
            }
            else if (strcmp(operation, "select") == 0)
             {
                    printf("enter table path : ");
                    scanf("%s", tablePath);

                    FILE *ptr = fopen(tablePath, "r");
                    if (ptr == NULL)
                    {
                        printf("file not here try path again .\n");
                        continue;  // Return to the main loop
                    }

                    // Read and print the content of the table
                    char line[256];
                    while (fgets(line, sizeof(line), ptr) != NULL)
                    {
                        printf("%s", line);
                    }

                    fclose(ptr);

             }
             else if (strcmp(operation, "insert") == 0)
            {
                //select table
                printf("enter table path : ");
                scanf("%s", tablePath);

                FILE *ptr = fopen(tablePath, "a");
                if (ptr == NULL)
                    {
                        printf("file path not exist \n");
                        exit(0);
                    }

                for (int i = 0; i < n; i++)
                    {
                    printf("Enter column name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                    scanf("%s %c", col_name[i], &col_type[i]);

                    // Check primary key & foreign key constraints
                    if (i == 0 && col_type[i] != 'i')
                        {
                            printf("invalid type ID . should be int (i) \n");
                            i--;
                        }
                    else if (i == 3 && col_type[i] != 'i')
                        {
                            printf("invalid type ID . should be int (i) \n");
                            i--;
                        }
                    else if (i == 3) {
                            //at end of file but depart_id
                        int departmentId = atoi(col_name[i]);

                        // check if departmentId exists in department.csv
                        if (!isForeignKeyValid("D:/department.csv", departmentId))
                            {
                                printf("invalid type ID . should be int (i) \n");
                                fclose(ptr);
                                return 0;  // Return without inserting
                           }
                    } else if (i == 0) {

                        int employeeId = atoi(col_name[i]);
                        if (!isIdUnique("D:/employee.csv", employeeId)) {
                            printf("ID should be unique .\n");
                            fclose(ptr);
                            return 0;  // Return without inserting
                        }
                    }

                    fprintf(ptr, "%s,%c,", col_name[i], col_type[i]);
                }
                fprintf(ptr, "\n");
                fclose(ptr);
                printf(" inserted successfully.....................\n");
            }
            else if (strcmp(operation, "update") == 0)
                {
                    printf("enter table path : ");
                    scanf("%s", tablePath);

                    int id;  //id
                    printf("enter id to update: ");
                    scanf("%d", &id);

                    // Declare arrays to store column names and types
                    char updated_col_name[max_size][max_size];
                    char updated_col_type[max_size];

                    updateRecord(tablePath, id, n, updated_col_name, updated_col_type);
              }
            else if (strcmp(operation, "exit") == 0)
                {
                    printf("done \n");
                    exit(1);
                }
            else
                {
                    printf("Invalid operation\n");
                }
    }

    return 0;
}

// Function to check if an ID is unique in a table
int isIdUnique(char *tablePath, int id) {  //read
        FILE *file = fopen(tablePath, "r");
        if (file == NULL) {
            printf("not found \n");
            exit(0);
        }

        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            // Assuming the ID is in the first column (modify as per your table structure)
            char *token = strtok(line, ",");
            int currentId = atoi(token);

            if (currentId == id) {
                fclose(file);
                return 0; // ID is not unique
            }
        }

        fclose(file);
        return 1; // ID is unique
}

// Function to check if a foreign key is valid in a table
int isForeignKeyValid(char *tablePath, int foreignKeyId) {
            FILE *file = fopen(tablePath, "r");
            if (file == NULL) {
                printf("not found \n");
                exit(0);
            }

            char line[256];
            while (fgets(line, sizeof(line), file) != NULL) {
                // Assuming the ID is in the first column and ignoring the rest (modify as per your table structure)
                char *token = strtok(line, ",");
                int currentId = atoi(token);

                if (currentId == foreignKeyId) {
                    fclose(file);
                    return 1; // Foreign key is valid
                }
            }

            fclose(file);
            return 0; // Foreign key is not valid
}

void updateRecord(char *tablePath, int id, int n, char col_name[max_size][max_size], char col_type[max_size]) {
            FILE *file = fopen(tablePath, "r+");
            if (file == NULL) {
                printf("not found \n");
                exit(0);
            }

            char line[256];
            long pos = -1;

            while (fgets(line, sizeof(line), file) != NULL) {
                pos = ftell(file); // Save the current file position

                char *token = strtok(line, ",");
                int currentId = atoi(token);

                if (currentId == id) {
                    // Check if the new department_id is unique before updating
                    int newDepartmentId;
                    printf("Enter updated department_id: ");
                    scanf("%d", &newDepartmentId);

                    if (!isForeignKeyValid("D:/department.csv", newDepartmentId)) {
                        printf("Error: Updated department_id must exist in the department table.\n");
                        fclose(file);
                        return;
                    }

                    // Update the record
                    fseek(file, pos, SEEK_SET); // Move the file position back to where the match was found
                    printf("Enter updated data for the record:\n");

                    for (int i = 0; i < n; i++) {
                        printf("Enter column name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                        scanf("%s %c", col_name[i], &col_type[i]);
                        fprintf(file, "%s,%c,", col_name[i], col_type[i]);
                    }
                    fprintf(file, "\n"); // Add a newline character to separate updated records

                    printf("updated successfully..........\n");
                    fclose(file);
                    return;
                }
            }

            fclose(file);
            printf("column with ID %d not found.\n", id);
}
