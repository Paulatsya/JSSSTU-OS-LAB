#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    
    if(argc<2){
        printf("Not passing the directory");
        exit(1);
    }
    if((dp=opendir(argv[1]))==NULL){
        printf("\n cant open dir %s\n",argv[1]);
        exit(1);
    }   
    while((dirp=readdir(dp))!= NULL){
        printf("%s\n",dirp->d_name);
    }
    return 0;
}