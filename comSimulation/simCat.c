#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[]){
    FILE *fp1;
    char ch;
    if(argc<2)
    {
        printf("Insufficient ammount of args\n");
        return 0;
    }
    fp1=fopen(argv[1], "r");
    if(fp1==NULL){
        printf("Error\n");
        return 0 ;

    }
    while((ch=fgetc(fp1))!=EOF)
        printf("%c",ch);
    fclose(fp1);
    return 0;
}