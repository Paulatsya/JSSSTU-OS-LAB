#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
int main(int argc, char  *argv[])
{
    int k=2,n1,n2,n3;
    key_t key=1234;
    int shmid=shmget(key,4096,0666);
    void *ptr=shmat(shmid,NULL,0);
    printf("[CHILD]");
    int i= atoi(argv[1]);
    n1=0;
    n2=1;
    sprintf(ptr,"%d",n1);
    ptr+=strlen(ptr);
    printf("%d",n1);
    sprintf(ptr,"%d",n2);
    ptr+=strlen(ptr);
    printf("%d",n2);
    while(k!=i){
        n3=n1+n2;
        sprintf(ptr,"%d",n3);
        printf("%d",n3);
        n1=n2;
        n2=n3;
        ptr+=strlen(ptr);
        k++;
    }
    return 0;
}
