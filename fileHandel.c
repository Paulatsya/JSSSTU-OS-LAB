#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER 30
int main(){
    int fd=open("abc.txt",O_RDWR),n;
    char buffer[BUFFER];

    printf("File descriptor is %d\n",fd);
    if(fd==-1){
        printf("Failed to open");
        exit(0);
    }
    //reading first 10 characters
    printf("\nreading first 10 characters\n");
    n=read(fd,buffer,10);
    write(1,buffer,n);

    //skipping 5 character from current position
    printf("\nskipping 5 character from current position\n");
    lseek(fd,5,SEEK_CUR);
    n=read(fd,buffer,10);
    write(1,buffer,n);

    //going to the 5th last char
    printf("\ngoing to the 5th last char\n");
    lseek(fd,-5,SEEK_END);
    n=read(fd,buffer,5);
    write(1,buffer,n);

    printf("going to 3rd char");
    lseek(fd,3,SEEK_SET);
    n=read(fd,buffer,5);
    write(1,buffer,n);

    close(fd);
    return 0;

}

