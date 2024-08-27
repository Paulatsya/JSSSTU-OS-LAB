#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    FILE *fp1;
    char ch,temp[100];
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
    fgets(temp,100,fp1);
    printf("%s",temp);
    return 0;
}