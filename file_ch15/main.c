#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* read file*/
    FILE *fileptr=NULL;
    fileptr=fopen("ghada.txt","r");
    if(fileptr==NULL){
        printf("not here \n");
        exit(1);
    }
    /*write file*/
    FILE *filewptr=NULL;
    filewptr=fopen("new.txt","a");
    if(filewptr==NULL){
        printf("not here \n");
        exit(1);
    }

    int x,y;
    char z,v;
    while(fscanf(fileptr,"%i %c %i %c",&x,&z,&y,&v)==4){
        printf("%i %c %i %c \n",x,z,y,v);
        fprintf(filewptr,"%d %c %d %c \n",x,z,y,v);
    }






    return 0;
}
