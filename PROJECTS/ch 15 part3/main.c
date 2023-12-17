#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char operation[10];  // Increased the size to accommodate longer input strings
    while (1) {
        printf("Enter Operation (create/select/insert/update/exit): ");
        scanf("%s", operation);
        char col_name[50][50];  // Increased the size to accommodate longer column names
        char col_type[50];
        char tablePath[50];
        int n;
        char col_val[50][50];
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
            /* Open file for reading and implement select operation*/

        } else if (strcmp(operation, "insert") == 0) {
            /* Open file for appending and implement insert operation*/
            printf("Enter full path for table: ");
            scanf("%s", tablePath);
            FILE *ptr = fopen(tablePath, "a");
            printf(" Enter number of columns: ");
            scanf("%d", &n);
            for(int i=0;i<n;i++){
                  printf(" Enter column name | type [f -> float , c -> character, i -> integer , s-> string ] %d: ", i + 1);
                  scanf("%s %c", col_name[i], &col_type[i]);
                  if (i==0 || i==3){
                    if(col_type[i]!='i'){
                            printf("enter valid type  : i \n");
                            i--;
                            }
                  }else if(i==1){
                     if(col_type[i]!='s'){
                            printf("enter valid type  : s \n");
                            i--;
                            }

                  }
                  else if(i==2){
                     if(col_type[i]!='f'){
                            printf("enter valid type  : f \n");
                            i--;
                            }
                  }
                fprintf(ptr, "%s,%c,", col_name[i], col_type[i]);

            }
            fclose(ptr);
        } else if (strcmp(operation, "exit") == 0) {
            printf("Finish\n");
            exit(1);
        } else {
            printf("Invalid operation\n");
        }
    }
    return 0;
}
