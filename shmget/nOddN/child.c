#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc, char *argv[])
{
    key_t key=1234;
    int shmid=shmget(key,4096,0666);
    void *ptr=shmat(shmid,NULL,0);
    int i =atoi(argv[1]);
    printf("[CHILD]");
    int k=0;
    for (int j = 0; j <= i; j++)
    {
        if((j%2)!=0){
            sprintf(ptr,"%d ",j);
            ptr+=strlen(ptr);
            printf("%d ",j);
        }
    }
    shmdt(ptr);

    return 0;
}


