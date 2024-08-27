#include<stdio.h>
#include<string.h>
int main(){
    char fn[100],pattern[100],temp[100];
    FILE *fp;
    printf("Enter file name>> ");
    scanf("%s",fn);
    printf("Enter pattern>> ");
    scanf("%s",pattern);
    fp=fopen(fn,"r");
    while(!feof(fp)){
        fgets(temp,100,fp);
        if(strstr(temp,pattern))
            printf("%s",temp);

    }
    return 0;
}