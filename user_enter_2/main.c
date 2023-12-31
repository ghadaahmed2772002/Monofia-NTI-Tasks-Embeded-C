#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>





char to_upper(char c) {
    int i=0;
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
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

int check_lower(char *str ) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_upper(str[i]) || !is_lower(str[i])) {
            return 1;
        }
    }
    return 0;
}


void capfun(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = to_upper(str[i]);
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

    if (check_lower(word)) {
        printf("error --> word have upper or special characters.\n");
    } else {
        capfun(word);
        printf("uppercase word: %s\n", word);
    }

    return 0;
}
