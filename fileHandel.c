#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define bufferSize 100

int main(){
    int fd,n;
    char buffer[bufferSize];
    fd=open("abc.txt",O_RDONLY);
    if(fd<0){
        printf("Error!!\n");
        exit(0);
    }
    printf("readinf first 10 char\n");
    write(1,buffer,read(fd,buffer,10));
    printf("\n");
    printf("skipping 5 char\n");
    lseek(fd,5,SEEK_CUR);
    write(1,buffer,read(fd,buffer,5));
    printf("\n");
    printf("5th last\n");
    lseek(fd,-5,SEEK_END);
    write(1,buffer,read(fd,buffer,5));
    printf("\n");
    printf("3rd Char\n");
    lseek(fd,3,SEEK_SET);
    write(1,buffer,read(fd,buffer,5));
    printf("\n");
    return 0;
}