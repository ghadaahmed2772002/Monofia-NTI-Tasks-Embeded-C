#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>





char to_lower(char c) {
    int i=0;
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}

char is_lower(char c) {
    int i=0;
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

char is_upper(char c) {
    int i=0;
    if (c >= 'A' && c<= 'Z') {
        return 1;
    }
    return 0;
}

int check_upper(char *str ) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_lower(str[i]) || !is_upper(str[i])) {
            return 1;
        }
    }
    return 0;
}


void capfun(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = to_lower(str[i]);
    }
}



int main() {
    char word[20];
    printf(" Enter a word: ");
    fgets(word, sizeof(word), stdin);
   char *p = strchr(word, '\n');
    if (p != NULL) {
        *p = '\0';
    }
    printf(" word: %s\n", word);

    if (check_upper(word)) {
        printf("error --> word have lower || special characters.\n");
    } else {
        capfun(word);
        printf("lowercase word: %s\n", word);
    }

    return 0;
}
