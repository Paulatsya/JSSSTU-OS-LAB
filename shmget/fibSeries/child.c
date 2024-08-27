#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(int argc, char  *argv[])
{
    key_t key=1;
    int shmid=shmget(key,4096,0666);
    void *ptr=shmat(shmid,NULL,0);
    int n1=0,n2=1,n3;
    int i=atoi(argv[1]);
    printf("[CHILD]");
    //print n1
    sprintf(ptr,"%d ",n1);
    ptr+=strlen(ptr);
    printf("%d ",n1);

    //print n2
    sprintf(ptr,"%d ",n2);
    ptr+=strlen(ptr);
    printf("%d ",n2);
    return 0;
}
