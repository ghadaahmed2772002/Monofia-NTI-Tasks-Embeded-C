#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{


    char word[20];

    printf(" Enter a word: ");
    fgets(word, sizeof(word), stdin);

    char *p = strchr(word, '\n');
    if (p != NULL) {
        *p = '\0';
    }
    printf(" word: %s\n", word);
    reverse_word(word);

    printf(" Reversed word: %s\n", word);



    return 0;
}

void reverse_word(char *str){
  int len=strlen(str);
  int i,j;
  for(i=0,j=len-1;i<j;i++,j--){

        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
  }


}
