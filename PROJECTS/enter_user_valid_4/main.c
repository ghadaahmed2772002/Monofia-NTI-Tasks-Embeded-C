#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_alpha(int c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


int is_valid_user_name(char *name) {

    if (!is_alpha(name[0])) {
        return 0;
    }

     if (strlen(name) <= 8)
        return 0;

    int count_underscore = 0;
    for (int i = 1; name[i] != '\0'; i++) {
        if (name[i] == '_') {
            count_underscore ++;
                    if (count_underscore >1 )
                               return 0;
        }else if (!isalnum(name[i]))
                    return 0;

    }

    return 1;
}

int main() {

    char word[20];
    printf(" Enter a userName: ");
    fgets(word, sizeof(word), stdin);
   char *p = strchr(word, '\n');
    if (p != NULL) {
        *p = '\0';
    }
    printf(" userName: %s\n", word);

    if (is_valid_user_name(word)) {
        printf("Valid UserName \n");
    } else {
        printf("Invalid UserName  ..\n");
    }

    return 0;
}
