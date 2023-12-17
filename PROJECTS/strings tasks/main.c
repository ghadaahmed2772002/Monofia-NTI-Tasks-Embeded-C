#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidUsername(const char *user_name) {
    int len = strlen(user_name);


    if (len <= 8) {
        return 0;
    }


    if (!isalpha(user_name[0])) {
        return 0;
    }


    int underscore_Count = 0;
    for (int i = 1; i < len - 1; i++) {
        if (user_name[i] == '_') {
            underscore_Count++;
        }
    }

    if (underscore_Count != 1) {
        return 0;
    }


    return 1;   //valid case despite not have underscore & <8 & first element is alpha
}

int main() {
    char user_name[50];

    printf("Enter your UserName: ");
    scanf("%s", user_name);


    if (isValidUsername(user_name)) {
        printf("The UserName  : %s is valid! \n ",user_name);
    } else {
        printf("The UserName  : %s is invalid.\n",user_name);
    }

    return 0;
}
