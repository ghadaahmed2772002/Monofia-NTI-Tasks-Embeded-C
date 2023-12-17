#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int isIdUnique(char *tablePath, int id);
int isForeignKeyValid(char *tablePath, int foreignKeyId);
void updateRecord(char *tablePath, int id, int n, char col_name[50][50], char col_type[50]);

int main() {
    char operation[10];
    while (1) {
        printf("Enter Operation (create/select/insert/update/exit): ");
        scanf("%s", operation);
        char col_name[50][50];
        char col_type[50];
        char tablePath[50];
        int n;
        printf("Enter number of columns: ");
        scanf("%d", &n);

        if (strcmp(operation, "create") == 0) {
                      // Changed to a single array to store column types
                    printf("Enter full path for table: ");
                    scanf("%s", tablePath);

                    FILE *ptr = fopen(tablePath, "w");
                    printf(" Enter number of columns: ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++) {
                        printf(" Enter column name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                        scanf("%s %c", col_name[i], &col_type[i]);
                    }

                    for (int i = 0; i < n; i++) {
                        fprintf(ptr, "%s,%c,", col_name[i], col_type[i]);
                    }

                    fclose(ptr);
        } else if (strcmp(operation, "select") == 0) {
            // Open file for reading and implement select operation
            // Add your code here
        } else if (strcmp(operation, "insert") == 0) {
                                printf("Enter full path for table: ");
                                scanf("%s", tablePath);

                                FILE *ptr = fopen(tablePath, "a");
                                printf("Enter number of columns: ");
                                scanf("%d", &n);

                                for (int i = 0; i < n; i++) {
                                    printf("Enter column name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                                    scanf("%s %c", col_name[i], &col_type[i]);

                                    // Check primary key and foreign key constraints
                                    if (i == 0 && col_type[i] != 'i') {
                                        printf("Invalid type for employee ID. Must be integer (i).\n");
                                        i--;
                                    } else if (i == 3 && col_type[i] != 'i') {
                                        printf("Invalid type for department ID. Must be integer (i).\n");
                                        i--;
                                    } else if (i == 3) {
                                        int departmentId = atoi(col_name[i]);
                                        if (!isForeignKeyValid("D:/department.csv", departmentId)) {
                                            printf("Invalid department ID. It must exist in the department table.\n");
                                            fclose(ptr);
                                            return 0;  // Return without inserting
                                        }
                                    } else if (i == 0) {
                                        int employeeId = atoi(col_name[i]);
                                        if (!isIdUnique("D:/employee.csv", employeeId)) {
                                            printf("Employee ID must be unique. Enter a different ID.\n");
                                            fclose(ptr);
                                            return 0;  // Return without inserting
                                        }
                                    }

                                    fprintf(ptr, "%s,%c,", col_name[i], col_type[i]);
                                }

                                fclose(ptr);
                                printf("Record inserted successfully.\n");
                            }
                        else if (strcmp(operation, "update") == 0) {
                                printf("Enter full path for table: ");
                                scanf("%s", tablePath);

                                int id;
                                printf("Enter ID to update: ");
                                scanf("%d", &id);

                                // Get the number of columns to update
                                int n;
                                printf("Enter the number of columns to update: ");
                                scanf("%d", &n);

                                // Declare arrays to store column names and types
                                char col_name[50][50];
                                char col_type[50];

                                updateRecord(tablePath, id, n, col_name, col_type);
}

         else if (strcmp(operation, "exit") == 0) {
            printf("Finish\n");
            exit(1);
        } else {
            printf("Invalid operation\n");
        }
    }
    return 0;
}

// Function to check if an ID is unique in a table
int isIdUnique(char *tablePath, int id) {
    FILE *file = fopen(tablePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
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
        perror("Error opening file");
        exit(EXIT_FAILURE);
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
void updateRecord(char *tablePath, int id, int n, char col_name[50][50], char col_type[50])  {
    FILE *file = fopen(tablePath, "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
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

            int n;
            for (int i = 0; i < n; i++) {
                printf("Enter column name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                scanf("%s %c", col_name[i], &col_type[i]);
                fprintf(file, "%s,%c,", col_name[i], col_type[i]);
            }

            printf("Record updated successfully.\n");
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Record with ID %d not found.\n", id);
}

